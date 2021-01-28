#include "graph.hpp"

namespace cjh {
  vertex::vertex(double x, double y) {
    coords[0] = x;
    coords[1] = y;
  };

  // accessor operartor
  double& vertex::operator[](int idx) {
    return coords[idx];
  };

  const double& vertex::operator[](int idx) const {
    return coords[idx];
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
    vertices.push_back(v);
    connectivity.push_back(list<uint32_t>());
  };

  void graph::addVertex(double x, double y){
    vertex_type vt;
    vt[0] = x; vt[1] = y;
    this -> addVertex(vt);
  };

  void graph::addEdge(uint32_t from_vertex, uint32_t to_vertex) {
    connectivity[from_vertex].push_back(to_vertex);
  };

  // get vertex
  typename graph::vertex_type& graph::getVertex(uint32_t id) {
    return vertices[id];
  };

  const typename  graph::vertex_type& graph::getVertex(uint32_t id) const {
    return vertices[id];
  };

  // get container with vertics
  vector<typename graph::vertex_type>& graph::getVertices() {
    return vertices;
  };

  const vector<typename graph::vertex_type>& graph::getVertices() const {
    return vertices;
  };

  // get iterators to move thorough connect info
  typename graph::list_type::iterator graph::getConnectivityStartIterator(uint32_t from_vertex_id) {
    return connectivity[from_vertex_id].begin();
  };

  typename graph::list_type::const_iterator graph::getConnectivityStartIterator(uint32_t from_vertex_id) const {
    return connectivity[from_vertex_id].begin();
  };

  typename graph::list_type::iterator graph::getConnectivityEndIterator(uint32_t to_vertex_id) {
    return connectivity[to_vertex_id].end();
  };

  typename graph::list_type::const_iterator graph::getConnectivityEndIterator(uint32_t to_vertex_id) const {
    return connectivity[to_vertex_id].end();
  };

  // clear the graph
  void graph::clear() {
    vertices.clear();
    connectivity.clear();
  };

  vector<typename graph::vertex_type> vertices;
  vector<typename graph::list_type> connectivity;
}