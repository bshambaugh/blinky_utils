#include <packet_parsing.h>
#include <gtest/gtest.h>

TEST(parse_packet, parse_a_packet) {

  string type = "";
  string curve = "";
  string payload = "";
  string source = "212001e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1160";
  parse_packet(&source,&type,&curve,&payload);
  EXPECT_EQ(source,"212001e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1160"); 
  EXPECT_EQ(type,"2");
  EXPECT_EQ(curve,"1200");
  EXPECT_EQ(payload,"1e34ec8b07258a84df2f3a8fbbc17e9bd17e65a42154078fee578db9f5fc1160");
}

