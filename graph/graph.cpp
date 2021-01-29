#include "graph.hpp"

namespace cjh {
  Vertex::Vertex(double x, double y) {
    coords[0] = x;
    coords[1] = y;
  };

  // accessor operartor
  double& Vertex::operator[](int idx) {
    return coords[idx];
  };

  const double& Vertex::operator[](int idx) const {
    return coords[idx];
  };

  // get data methods
  struct Vertex::data_type& Vertex::getData() {
    return data;
  };
  const struct Vertex::data_type& Vertex::getData() const {
    return data;
  };

  // struct data

  // modify graph state
  void Graph::addVertex(const vertex_type& v) {
    vertices.push_back(v);
    connectivity.push_back(list<uint32_t>());
  };

  void Graph::addVertex(double x, double y){
    vertex_type vt;
    vt[0] = x; vt[1] = y;
    this -> addVertex(vt);
  };

  void Graph::addEdge(uint32_t from_vertex, uint32_t to_vertex) {
    connectivity[from_vertex].push_back(to_vertex);
  };

  // get vertex
  typename Graph::vertex_type& Graph::getVertex(uint32_t id) {
    return vertices[id];
  };

  const typename  Graph::vertex_type& Graph::getVertex(uint32_t id) const {
    return vertices[id];
  };

  // get container with vertics
  vector<typename Graph::vertex_type>& Graph::getVertices() {
    return vertices;
  };

  const vector<typename Graph::vertex_type>& Graph::getVertices() const {
    return vertices;
  };

  // get iterators to move thorough connect info
  typename Graph::list_type::iterator Graph::getConnectivityStartIterator(uint32_t from_vertex_id) {
    return connectivity[from_vertex_id].begin();
  };

  typename Graph::list_type::const_iterator Graph::getConnectivityStartIterator(uint32_t from_vertex_id) const {
    return connectivity[from_vertex_id].begin();
  };

  typename Graph::list_type::iterator Graph::getConnectivityEndIterator(uint32_t to_vertex_id) {
    return connectivity[to_vertex_id].end();
  };

  typename Graph::list_type::const_iterator Graph::getConnectivityEndIterator(uint32_t to_vertex_id) const {
    return connectivity[to_vertex_id].end();
  };

  // clear the graph
  void Graph::clear() {
    vertices.clear();
    connectivity.clear();
  };

  vector<typename Graph::vertex_type> vertices;
  vector<typename Graph::list_type> connectivity;
}