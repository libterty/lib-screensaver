#include <math.h>
#include <time.h>
#include <random>
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

  void createRandomCompleteGraph(double width, double height,
                                 uint32_t min_num_vertices, uint32_t max_num_vertices,
                                 Graph& G) {
    // get the min and max num of vertices, ensure correct input
    uint32_t min_n = min_num_vertices < max_num_vertices ? min_num_vertices : max_num_vertices;
    uint32_t max_n = min_num_vertices < max_num_vertices ? max_num_vertices : min_num_vertices;

    // define obj related to randomization
    default_random_engine g(time(nullptr));
    uniform_real_distribution<double> U(0, 1);

    // clear or reset graph
    G.clear();

    // select number of vertices to generate
    double s = U(g);
    uint32_t num_vertices = min_n * s + (1 - s) * max_n;

    // define the max radius for the vertices from center
    double qw = width / 4.0, qh = height / 4.0;
    const double max_r = sqrt(qw * qw + qh * qh);

    // double a random angle rate
    const double omega = (2 * U(g) - 1);

    // compute the change in radius relatvie with neighboring
    const double dTheta = 2 * M_PI / static_cast<double>(num_vertices);

    // loop through and create vertices
    for(uint32_t i = 0; i < num_vertices; ++i) {
      /* code */
      // compute components
      double b = i * dTheta;
      double x = 0.5 * width + max_r * cos(b);
      double y = 0.5 * height + max_r * sin(b);

      // add the vertex to graph
      G.addVertex(x, y);

      // get and assign dat
      auto& data = G.getVertex(i).getData();
      data.radius = max_r;
      data.omega = omega;
      data.bios = b;
    }

    for (uint32_t i = 0; i < num_vertices; ++i) {
      /* code */
      for (uint32_t j = i + 1; j < num_vertices; ++j) {
        /* code */
        G.addVertex(i, j);
      }
    }
  }

  vector<typename Graph::vertex_type> vertices;
  vector<typename Graph::list_type> connectivity;
}
