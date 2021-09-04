#include "broadcast_server.h"

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

broadcast_server::broadcast_server() {
	m_server.init_asio();

	m_server.set_access_channels(websocketpp::log::alevel::access_core);
	m_server.set_error_channels(websocketpp::log::elevel::all ^ websocketpp::log::alevel::frame_payload);

	m_server.set_open_handler(bind(&broadcast_server::on_open, this, ::_1));
	m_server.set_close_handler(bind(&broadcast_server::on_close, this, ::_1));
	//m_server.set_message_handler(bind(&broadcast_server::on_message, this, ::_1, ::_2));
}

void broadcast_server::on_open(connection_hdl hdl) {
	m_connections.insert(hdl);
}

void broadcast_server::on_close(connection_hdl hdl) {
	m_connections.erase(hdl);
}

void broadcast_server::on_message(connection_hdl hdl, server::message_ptr msg) {
	for (auto it : m_connections) {
		m_server.send(it, msg);
	}
}

void broadcast_server::run(uint16_t port) {
	m_server.listen(port);
	m_server.start_accept();
	m_server.run();
}

void broadcast_server::broadcast(const char* msg) {
	for (auto it : m_connections) {
		m_server.send(it, std::string(msg), websocketpp::frame::opcode::text);
	}
}

typedef std::set<connection_hdl, std::owner_less<connection_hdl>> con_list;

server m_server;
con_list m_connections;