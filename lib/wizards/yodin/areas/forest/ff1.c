inherit "room/room";

reset(arg)
{

add_exit("forest","ff2.c");
add_exit("north","out: 256 35");
add_exit("northeast","out: 256 35");
add_exit("east","out: 256 35");
add_exit("southeast","out: 256 35");
add_exit("south","out: 256 35");
add_exit("southwest","out: 256 35");
add_exit("west","out: 256 35");
add_exit("northwest","out: 256 35");

short_desc = "Very old forest.";
long_desc =
"Very old forest with tall trees and bushes everywhere.\n" +
"Some animals are here eating grass and undergrowth.\n" +
"Animals don't seem to be scared at all.The breezing\n" +
"wind creates some strange noises.\n";



}