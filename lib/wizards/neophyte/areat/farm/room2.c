inherit "room/room";
reset (arg) {
    if(arg) return;
        short_desc = "Front of that building";
        long_desc = "Farm house is built center of this courtyard, the house is painted\n"+
                    "red and white. Large chimney made of red bricks is on the roof of house\n"+
                    "and lots of smoke is rising from the chimney. Windows of the house are\n"+
                    "opened.\n";
add_exit("house","house");
add_exit("south","room4");
add_exit("west","room1");
items = allocate(6);
items[0] = "ladder";
items[1] = "A tall wooden ladders are placed front of the wall. Ladders\n"+
           "look quite old and fragile";
items[2] = "windows";
items[3] = "They are opened and wind is going in the house";
items[4] = "chimney";
items[5] = "A chimney is built on the roof. A lot of smoke is coming from it";
}

