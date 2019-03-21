#pragma once

#include <gtest/gtest.h>

#include "../ListOfNames/Element.cpp"
#include "../ListOfNames/List.cpp"

TEST(ElementTest, GetPrev_SetPrev_Test)
{
    Element* elem1 = new Element("1");
    Element* elem2 = new Element("2");

    elem2->SetPrev(elem1);

    EXPECT_EQ(elem2->GetPrev(), elem1);

    delete elem1;
    delete elem2;
}

TEST(ElementTest, GetNext_SetNext_Test)
{
    Element* elem1 = new Element("1");
    Element* elem2 = new Element("2");

    elem1->SetNext(elem2);

    EXPECT_EQ(elem1->GetNext(), elem2);

    delete elem1;
    delete elem2;
}

TEST(ElementTest, GetData_Test)
{
    Element* elem1 = new Element("123");

    EXPECT_EQ(elem1->GetData(), "123");

    delete elem1;
}

class ListTest : public ::testing::Test
{
private:
  void SetUp() override
  {
      list = new List();
  }

  void TearDown() override
  {
      delete  list;
  }

public:
  List* list;
};

TEST_F(ListTest, Add_GetData_Test)
{
    list->Add("123");

    EXPECT_EQ(list->GetHead()->GetData(), "123");
}

TEST_F(ListTest, GetSize_Test)
{
    unsigned int size = list->GetSize();

    list->Add("123");

    EXPECT_EQ(list->GetSize(), size + 1);
}

TEST_F(ListTest, Clear_Test)
{
    unsigned int size = list->GetSize();

    list->Add("123");
    list->Add("123");
    list->Add("123");

    EXPECT_EQ(list->GetSize(), size + 3);

    list->Clear();

    EXPECT_EQ(list->GetSize(), 0);
}
