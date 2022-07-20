#include <gtest/gtest.h>

#include "../src/server_functions.hpp"

TEST(client_server_app, first_test)
{
    char* buffer = "20 monday.txt";
    string str = count_of_words(buffer);
    EXPECT_EQ(3, stoi(str));
}

TEST(client_server_app, second_test)
{
    char* buffer = "Я monday.txt";
    string word, file_name; 
    split_str(word, file_name, buffer);
    EXPECT_EQ("Я", word);
    EXPECT_EQ("monday.txt", file_name);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}