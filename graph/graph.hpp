#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <cstdint>
#include <vector>
#include <list>

using namespace std;

namespace cjh {

  // class that represent vertex of graph
  class vertex {
  public:
    // structure
    struct data_type {
      double radius;
      double omega;
      double bios;
    };
    // ctor
    vertex() = default;
    vertex(double x, double y);

    // get data methods
    struct data_type& getData();
    const struct data_type& getData() const;
  
  private:
    double coords[2];
    struct data_type data;
  };

  // class represent graph
  class graph {
  public:

    using vertex_type = vertex;
    using list_type = list<uint32_t>;

    // ctor/dtor
    graph() = default;
    ~graph() = default;

    // modify graph state
    void addVertex(const vertex_type& v);
    void addVertex(double x, double y);
    void addEdge(uint32_t from_vertex, uint32_t to_vertex);

    // get vertex
    vertex_type& getVertex(uint32_t id);
    const vertex_type& getVertex(uint32_t id) const;

    // get container with vertics
    vector<vertex_type>& getVertices();
    const vector<vertex_type>& getVertices() const;

    // get iterators to move thorough connect info
    list_type::iterator getConnectivityStartIterator(uint32_t from_vertex_id);
    list_type::const_iterator getConnectivityStartIterator(uint32_t from_vertex_id) const;
    list_type::iterator getConnectivityEndIterator(uint32_t to_vertex_id);
    list_type::const_iterator getConnectivityEndIterator(uint32_t to_vertex_id) const;

    // clear the graph
    void clear();

  private:

    vector<vertex_type> vertices;
    vector<list_type> connectivity;
  
  };
} // namespace cjh

#endif /* graph_hpp */