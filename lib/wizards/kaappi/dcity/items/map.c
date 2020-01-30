short() { return "A map of Amaranthgard"; }

long(str) {

write("                                       \n"+
      "                         E = City gates\n"+
      " ###################     V = Warehouse\n"+                
      " #    V            #     K = City Hall\n"+
      " #  A |            #     S = General store\n"+
      " #+---+-9-+---+---+#     B = Bakery\n"+
      " #| B |       | H |#     W = Weapon shop\n"+
      " #|S W| ##### |  H|#     G = Guard barracks\n"+ 
      " #|   | #   # | H |#     H = Houses\n"+
      " #+-8-+ # K # +---+#     A = Armour Shop\n"+
      " #|   | #   # |   |#     p = park\n"+    
      " #2  G| ##-## |G  7#\n"+      
      " #|   | p | p |   |#     1 = Thrmo Street\n"+
      " #+---+---o---+-6-+#     2 = Kilvim Street\n"+
      " #| H |   |   | H |#     3 = Dalvur Street\n"+
      " #|H H3  H4H  5H H|#     4 = Thordim Street\n"+
      " #| H |   |   | H |#     5 = Gimbar Street\n"+
      " #+---+-1-+---+---+#     6 = Thrala Street\n"+
      " #########E#########     7 = Bila Street\n"+
      "                         8 = Bolain Street\n"+
      "                         9 = Mormain Street\n");
}

id(str) { return str == "map"; }

get() { 
   return 1;
}
