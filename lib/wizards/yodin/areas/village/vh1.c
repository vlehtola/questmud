inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Vilage of happines.";
long_desc =
"You have arrived in a small village. There are lots of people, \n" +
"everybody seems very happy like there was no evil in the \n" +
"world. Few small huts and some shops can be seen in the distance.\n" +
"Large wooden sign is in front of you.\n";

add_exit("leave", "outmap: 97 112");
add_exit("northeast", "vh2.c");
add_exit("southeast", "vh24.c");

items = allocate (2);
items[0] = "sign";
items[1] = "*********************************************\n" +
           "****                                      ***\n" +
           "****         VILLAGE OF HAPPINESS         ***\n" +
           "****                                      ***\n" +
           "****                                      ***\n" +
           "*********************************************\n";
}
