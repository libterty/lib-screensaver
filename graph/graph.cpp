#include "graph.hpp"

namespace cjh {
  vertex::vertex(double x, double y) {
    coords[0] = x;
    coords[1] = y;
  };

  // get data methods
  struct vertex::data_type& vertex::getData() {
    return data;
  };
  const struct vertex::data_type& vertex::getData() const {
    return data;
  };

  // struct data

  // modify graph state
  void graph::addVertex(const vertex_type& v) {

  };

  void graph::addVertex(double x, double y){

  };

  void graph::addEdge(uint32_t from_vertex, uint32_t to_vertex) {

  };

  // get vertex
  typename graph::vertex_type& graph::getVertex(uint32_t id) {

  };
  const typename  graph::vertex_type& graph::getVertex(uint32_t id) const {

  };

  // get container with vertics
  vector<typename graph::vertex_type>& graph::getVertices() {

  };
  const vector<typename graph::vertex_type>& graph::getVertices() const {

  };

  // get iterators to move thorough connect info
  typename graph::list_type::iterator graph::getConnectivityStartIterator(uint32_t from_vertex_id) {

  };

  typename graph::list_type::const_iterator graph::getConnectivityStartIterator(uint32_t from_vertex_id) const {

  };

  typename graph::list_type::iterator graph::getConnectivityEndIterator(uint32_t to_vertex_id) {

  };

  typename graph::list_type::const_iterator graph::getConnectivityEndIterator(uint32_t to_vertex_id) const {

  };

  // clear the graph
  void graph::clear() {

  };

  vector<typename graph::vertex_type> vertices;
  vector<typename graph::list_type> connectivity;
}