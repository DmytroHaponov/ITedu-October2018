#pragma once

#include <gtest/gtest.h>

#include "../ListReverse/node.h"

TEST(NodeTest, GetDataTest)
{
    Node node(3);

    EXPECT_EQ(node.GetData(), 3);
}

TEST(NodeTest, SetNext_GetNext_Test)
{
    Node* node = new Node(3);
    Node* next = new Node(4);

    EXPECT_EQ(node->GetNext(), nullptr);
    node->SetNext(next);
    EXPECT_EQ(node->GetNext(), next);

    delete node;
    delete next;
}
