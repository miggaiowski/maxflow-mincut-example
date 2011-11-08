#include <stdio.h>
#include "graph.h"

int main() {
  typedef Graph<double,double,double> GraphType;

  // !!! Exemplo da página 659 do Cormen !!!

  // Cria grafo com número estimado de vértices=4 e arcos=6.
  GraphType *g = new GraphType(4, 6); 

  // Criando 4 vértices
  g->add_node(); // cria vertice 0
  g->add_node(); // cria vertice 1
  g->add_node(); // 2
  g->add_node(); // 3

  g->add_tweights(0, 16, 0); // Cria arco SOURCE->0 e 0->SINK com capacidades 16 e 0, respectivamente.
  g->add_tweights(1, 13, 0); // SOURCE->1
  g->add_tweights(2, 0, 20); // 3 -> SINK
  g->add_tweights(3, 0, 4.1); // 4 -> SINK

  g->add_edge(0, 1, 10, 4); // Cria aresta entre 0 e 1 com capacidades 10 e 4 (ida e volta)
  g->add_edge(0, 2, 12, 0);
  g->add_edge(1, 2, 0, 9);
  g->add_edge(1, 3, 14, 0);
  g->add_edge(2, 3, 0, 7);

  double flow = g -> maxflow();

  printf("Flow = %lf\n", flow);
  printf("Minimum cut:\n");
  for (int i = 0; i < 4; i++) {
    if (g->what_segment(i) == GraphType::SOURCE)
      printf("node%d is in the SOURCE set\n", i);
    else
      printf("node%d is in the SINK set\n", i);
  }

  // Pegando os arcos do corte minimo.
  GraphType::arc_id a;
  a = g->get_first_arc();
  GraphType::node_id u, v;
  printf("Arcos do corte mínimo:\n");
  for (int i = 0; i < g->get_arc_num(); i++) {
    g->get_arc_ends(a, u, v);
    if (g->what_segment(u) != g->what_segment(v)) {
      printf("%d -> %d\n", u, v);
    }
    a = g->get_next_arc(a);
  }


  // Este trecho imprime a rede residual
  // GraphType::arc_id a;
  // a = g->get_first_arc();
  // GraphType::node_id u, v;
  // for (int i = 0; i < g->get_arc_num(); i++) {
  //   g->get_arc_ends(a, u, v);
  //   printf("Residual %d %d: %d\n", u, v, g->get_rcap(a));
  //   a = g->get_next_arc(a);
  // }

  // Desaloca o grafo
  delete g;

  return 0;
}
