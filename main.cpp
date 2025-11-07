#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BinarySearchTree.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>

using namespace std;

TEST_CASE("BinarySearchTree basic operations") {
  BinarySearchTree<int> B;
  B.insert(10);

  B.insert(4);
  B.insert(2);
  B.insert(15);
  B.insert(31);
  B.insert(1);
  B.insert(56);
  CHECK(B.toInorderStr() == "1,2,4,10,15,31,56");
  B.remove(1);
  B.remove(4);
  CHECK(B.toInorderStr()=="2,10,15,31,56");   // Testing remove() method
  B.insert(3);
  CHECK(B.toInorderStr()=="2,3,10,15,31,56");   // Further testing insert() method
  CHECK(B.contains(31));
  CHECK(!B.contains(100));    // Testing contains() method


  // CHECK(B.BFT() == "[[10],[4,15],[2,31],[1,56]]");
  BinarySearchTree<int> C;
  for (auto e :
       {16, 8, 24, 28, 20, 12, 4, 2, 6, 10, 14, 18, 22, 26, 30, 15, 7, 3}) {
    C.insert(e);
  }

  CHECK(C.toInorderStr() == "2,3,4,6,7,8,10,12,14,15,16,18,20,22,24,26,28,30");
  CHECK(C.BFT() == "[[16],[8,24],[4,12,20,28],[2,6,10,14,18,22,26,30],[3,7,15]]");
  BinarySearchTree<int> D;
  for (auto e: {8,3,10,1,6,14,4,7,13}){D.insert(e);
  }
  CHECK(D.BFT() == "[[8],[3,10],[1,6,14],[4,7,13]]");

  BinarySearchTree<int> E;  // Testing output when root is nullptr
  CHECK(E.BFT()=="");

  BinarySearchTree<int> F;  // Testing output with just root node
  F.insert(0);
  CHECK(F.BFT()=="[[0]]");

  BinarySearchTree<int> G;  // Testing output with elements to the right of root
  G.insert(0);
  G.insert(1);
  G.insert(2);
  G.insert(3);
  G.insert(4);

  CHECK(G.BFT()== "[[0],[1],[2],[3],[4]]");

  BinarySearchTree<int> H;  // Testing output with elements to the left of root
  H.insert(4);
  H.insert(3);
  H.insert(2);
  H.insert(1);
  H.insert(0);

  CHECK(H.BFT()== "[[4],[3],[2],[1],[0]]");




}
