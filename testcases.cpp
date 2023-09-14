/* -------------------------------------------------------
 * @file tests.cpp
 * @author Rahin Jain
 * **in colaboration with @Nirgun Goel and @Aarav Surkatha
 * @Nirgun Goel - UIN:677368626 netID: ngoel9
 * @Aarav Surkatha -UIN 667714562 netID: asurka2
 * @Rahin Jain -UIN 665219123 netID: rjain56
 * CS 251 - UIC spring '23
 * Assignment details and provided code are created and
 * owned by Adam T Koehler, PhD - Copyright 2023.
 * -----------------------------------------------------*/

// Catch 1.0 Framework Testing
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "priorityqueue.h"

using namespace std;

// Created by Nirgun G.
TEST_CASE("(0) Default constructor")
{
    priorityqueue<int> Q;
    REQUIRE(Q.Size() == 0);
    REQUIRE(Q.getRoot() == nullptr);
}

TEST_CASE("(1) enqueue function")
{
    // Designed and created by Aarav S.
    SECTION("Testing insertion in empty tree")
    {
        priorityqueue<string> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        // adding root
        Q.enqueue("Jack", 4);
        REQUIRE(Q.Size() == 1);
        REQUIRE(Q.toString() == "4 value: Jack\n");
        REQUIRE(Q.getRoot() != nullptr);
    }

        // Designed and created by Aarav S.
    SECTION("Testing insertion of smaller values")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 2);
        Q.enqueue('C', 1);
        Q.enqueue('D', 4);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "1 value: C\n2 value: B\n4 value: D\n5 value: A\n");
    }

        // Designed and created by Aarav S.
    SECTION("Testing insertion of larger values")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 9);
        Q.enqueue('C', 6);
        Q.enqueue('D', 8);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "5 value: A\n6 value: C\n8 value: D\n9 value: B\n");
    }

        // Designed and created by Nirgun G.
    SECTION("Testing duplicated values on root")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 5);
        Q.enqueue('C', 5);
        Q.enqueue('D', 5);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "5 value: A\n5 value: B\n5 value: C\n5 value: D\n");
    }

        // Designed and created by Nirgun G.
    SECTION("Testing duplicated values on root")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 5);
        Q.enqueue('C', 5);
        Q.enqueue('D', 5);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "5 value: A\n5 value: B\n5 value: C\n5 value: D\n");
    }

        // Designed and created by Nirgun G.
    SECTION("Testing insertion on both sides of the tree")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 1);
        Q.enqueue('C', 7);
        Q.enqueue('D', 2);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "1 value: B\n2 value: D\n5 value: A\n7 value: C\n");
    }

        // Designed and created by Rahin J.
    SECTION("Testing duplicated values on every node")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 1);
        Q.enqueue('C', 7);
        Q.enqueue('D', 2);
        Q.enqueue('E', 5);
        Q.enqueue('F', 1);
        Q.enqueue('G', 7);
        Q.enqueue('H', 2);
        REQUIRE(Q.Size() == 8);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "1 value: B\n1 value: F\n2 value: D\n2 value: H\n5 value: A\n5 value: E\n7 value: C\n7 value: G\n");
    }

        // Designed and created by Rahin J.
    SECTION("Testing multiple duplicated values")
    {
        priorityqueue<char> Q;
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.Size() == 0);

        Q.enqueue('A', 5);
        Q.enqueue('B', 5);
        Q.enqueue('C', 5);
        Q.enqueue('D', 5);
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.getRoot() != nullptr);
        REQUIRE(Q.toString() == "5 value: A\n5 value: B\n5 value: C\n5 value: D\n");
    }

}

TEST_CASE("(2) dequeue functon")
{
    // Designed and created by Nirgun G.
    SECTION("dequeueing an empty tree") {

        priorityqueue <char> Q;
        REQUIRE(Q.Size() == 0);
        REQUIRE(Q.getRoot() == nullptr);
        REQUIRE(Q.dequeue() == NULL);
    }

        // Designed and created by Nirgun G.
    SECTION("tree root is the left most node") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 4);
        Q.enqueue('C', 6);

        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.peek() == 'A');
        REQUIRE(Q.dequeue() == 'A');
        REQUIRE(Q.peek() == 'B');
        REQUIRE(Q.Size() == 2);
    }

        // Designed and created by Rahin J.
    SECTION("if root has dups and is the left most node") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 1);
        Q.enqueue('C', 1);
        Q.enqueue('D', 4);
        Q.enqueue('E', 6);

        REQUIRE(Q.Size() == 5);
        REQUIRE(Q.peek() == 'A');
        REQUIRE(Q.dequeue() == 'A');
        REQUIRE(Q.peek() == 'B');
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.dequeue() == 'B');
        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.peek() == 'C');
    }

        // Designed and created by Rahin J.
    SECTION("dequeueing left most node") {

        priorityqueue<char> Q;
        Q.enqueue('A', 6);
        Q.enqueue('B', 3);
        Q.enqueue('C', 9);

        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.peek() == 'B');
        REQUIRE(Q.dequeue() == 'B');
        REQUIRE(Q.peek() == 'A');
        REQUIRE(Q.Size() == 2);
    }

        // Designed and created by Rahin J.
    SECTION("dequeueing left most node in multi level tree") {

        priorityqueue<char> Q;
        Q.enqueue('A', 6);
        Q.enqueue('B', 3);
        Q.enqueue('C', 1);
        Q.enqueue('D', 4);
        Q.enqueue('E', 9);

        REQUIRE(Q.Size() == 5);
        REQUIRE(Q.peek() == 'C');
        REQUIRE(Q.dequeue() == 'C');
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.peek() == 'B');
    }

        // Designed and created by Aarav S.
    SECTION("left most node has a right child") {

        priorityqueue<char> Q;
        Q.enqueue('A', 6);
        Q.enqueue('B', 3);
        Q.enqueue('C', 1);
        Q.enqueue('D', 2);
        Q.enqueue('E', 4);
        Q.enqueue('F', 9);

        REQUIRE(Q.Size() == 6);
        REQUIRE(Q.peek() == 'C');
        REQUIRE(Q.dequeue() == 'C');
        REQUIRE(Q.Size() == 5);
        REQUIRE(Q.peek() == 'D');
        REQUIRE(Q.dequeue() == 'D');
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.peek() == 'B');
    }

        // Designed and created by Aarav S.
    SECTION ("left most node has dups") {

        priorityqueue<char> Q;
        Q.enqueue('A', 6);
        Q.enqueue('B', 3);
        Q.enqueue('C', 1);
        Q.enqueue('D', 1);
        Q.enqueue('E', 1);
        Q.enqueue('F', 4);
        Q.enqueue('G', 9);

        REQUIRE(Q.Size() == 7);
        REQUIRE(Q.peek() == 'C');
        REQUIRE(Q.dequeue() == 'C');
        REQUIRE(Q.Size() == 6);
        REQUIRE(Q.peek() == 'D');
        REQUIRE(Q.dequeue() == 'D');
        REQUIRE(Q.Size() == 5);
        REQUIRE(Q.peek() == 'E');
        REQUIRE(Q.dequeue() == 'E');
        REQUIRE(Q.Size() == 4);
        REQUIRE(Q.peek() == 'B');
    }
}

TEST_CASE("(3) assignment operator")
{
    // Designed and created by Aarav S.
    SECTION ("tree B is empty") {

        priorityqueue<char> A;
        A.enqueue('A', 6);
        A.enqueue('B', 3);
        A.enqueue('C', 1);
        A.enqueue('D', 1);
        A.enqueue('E', 1);
        A.enqueue('F', 4);
        A.enqueue('G', 9);
        REQUIRE(A.Size() == 7);
        REQUIRE(A.peek() == 'C');

        priorityqueue<char> B;
        REQUIRE(B.Size() == 0);
        REQUIRE(B.getRoot() == nullptr);
        REQUIRE(B.peek() == NULL);

        B = A;
        REQUIRE(B.Size() == 7);
        REQUIRE(B.peek() == 'C');
        REQUIRE(B == A);

    }

        // Designed and created by Aarav S.
    SECTION ("tree B needs clearing") {

        priorityqueue<char> A;
        A.enqueue('A', 6);
        A.enqueue('B', 3);
        A.enqueue('C', 1);
        A.enqueue('D', 1);
        A.enqueue('E', 1);
        A.enqueue('F', 4);
        A.enqueue('G', 9);
        REQUIRE(A.Size() == 7);
        REQUIRE(A.peek() == 'C');

        priorityqueue<char> B;
        B.enqueue('n', 47);
        B.enqueue('p', 3);
        B.enqueue('g', 10);
        B.enqueue('h', 22);
        REQUIRE(B.Size() == 4);
        REQUIRE(B.peek() == 'p');

        B = A;
        REQUIRE(B.Size() == 7);
        REQUIRE(B.peek() == 'C');
        REQUIRE(B == A);
    }
}

TEST_CASE("(4) Comparison operator")
{

    // Designed and created by Rahin J.
    SECTION("basic working") {
        priorityqueue<char> pqA;
        pqA.enqueue('A', 5);
        pqA.enqueue('B', 4);
        pqA.enqueue('C', 7);

        priorityqueue<char> pqB;
        pqB.enqueue('A', 5);
        pqB.enqueue('B', 4);
        pqB.enqueue('C', 7);

        REQUIRE((pqA == pqB) == true);
    }

        // Designed and created by Rahin J.
    SECTION("both trees are empty") {
        priorityqueue<char> A;
        priorityqueue<char> B;
        REQUIRE(A.getRoot() == nullptr);
        REQUIRE(A.Size() == 0);
        REQUIRE(B.getRoot() == nullptr);
        REQUIRE(B.Size() == 0);

        REQUIRE(A == B);
    }

        // Designed and created by Rahin J.
    SECTION("if one tree is empty and other isn't") {
        priorityqueue<char> A;
        A.enqueue('A', 2);

        REQUIRE(A.peek() == 'A');
        REQUIRE(A.Size() == 1);

        priorityqueue<char> B;
        REQUIRE(B.getRoot() == nullptr);
        REQUIRE(B.Size() == 0);

        REQUIRE(!(A == B));
    }
}

TEST_CASE("(5) clear function")
{
    // Designed and created by Nirgun G.
    SECTION("clearing empty tree") {

        priorityqueue<char> Q;
        REQUIRE(Q.Size() == 0);
        Q.clear();
        REQUIRE(Q.Size() == 0);
        REQUIRE(Q.getRoot() == nullptr);
    }

        // Designed and created by Nirgun G.
    SECTION("clearing a proper tree without dups") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 4);
        Q.enqueue('C', 6);

        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.peek() == 'A');
        Q.clear();
        REQUIRE(Q.Size() == 0);
        REQUIRE(Q.getRoot() == nullptr);
    }

        // Designed and created by Nirgun G.
    SECTION("clearing a proper tree with dups") {
        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 4);
        Q.enqueue('C', 6);
        Q.enqueue('D', 1);
        Q.enqueue('E', 1);
        Q.enqueue('F', 6);

        REQUIRE(Q.Size() == 6);
        REQUIRE(Q.peek() == 'A');
        Q.clear();
        REQUIRE(Q.Size() == 0);
        REQUIRE(Q.getRoot() == nullptr);
    }
}

TEST_CASE("(6) next function")
{
    // Designed and created by Aarav S.
    SECTION ("when next is a right node") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 4);
        Q.enqueue('C', 6);
        Q.begin();
        char b = 'B';
        int num = 4;
        REQUIRE(Q.next(b, num));
        REQUIRE(Q.Size() == 3);
    }

        // Designed and created by Aarav S.
    SECTION("when next is the parent") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 4);
        Q.enqueue('C', 6);
        Q.begin();
        char b = 'B';
        int num = 4;
        char c = 'C';
        int num2 = 6;
        REQUIRE(Q.next(b, num));
        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.next(c, num2));
    }

        // Designed and created by Rahin J.
    SECTION("when next is a dup value") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.enqueue('B', 1);
        Q.enqueue('C', 1);
        Q.begin();
        char b = 'B';
        int num = 1;
        char c = 'C';
        REQUIRE(Q.next(b, num));
        REQUIRE(Q.Size() == 3);
        REQUIRE(Q.next(c, num));
    }

        // Designed and created by Rahin J.
    SECTION("when there isn't any valid next") {

        priorityqueue<char> Q;
        Q.enqueue('A', 1);
        Q.begin();
        char b = 'B';
        int num = 1000;
        REQUIRE(Q.next(b, num));
        REQUIRE(Q.Size() == 1);
    }
}
