inherit "room/room";

reset(arg) {
  add_exit("out", "/wizards/ahma/orc/village/sq04");
  short_desc = "In the artifact shop";
  long_desc = "Two green-glowing pieces of stone lay a mystical atmosphere over\n" + 
              "this absolutely exceptional shop. The shelves are full of more and\n" + 
              "more odd items and pieces of furniture. Some of the items are just\n" + 
              "very old, but some are fascinating because of their different-coloured\n" + 
              "glows and auras. All of the items are surrounded by a bluish strong-\n" + 
              "looking force field, so that they cannot be stolen or even touched. A correct\n" + 
              "releasing spell is needed to unwind the force fields. A piece of\n" + 
              "paper has been attached on the wall.\n";
              
  items = allocate(2);
  items[0] = "paper";
  items[1] = "Antique items are sold with 500,000 bronzes and up.\n" + 
             "Magical items are sold with 1,200,000 bronzes and up.\n" + 
             "Unique items are sold with 2,500,000 bronzes and up.\n" + 
             "Type 'list' to get list of stocked items.\n" +
             "No bargain-possibility. No insurance included with items.\n" + 
             "Have a nice day";
  property = ({"no_skill", "no_spell", "no_kill"});  

  if(!present("naglah", this_object())) { move_object(clone_object("/wizards/ahma/orc/mob/shopkeeper03"), this_object()); }
}

init() {
  ::init();
  add_action("list", "list");
  add_action("hep", "buy");
}

list() {
write("+----Name------------------------------------------------+-Price------+\n" + 
      "| 1. Round mirror with brass frames <antique>            |  500000 br |\n" +
      "| 2. Kelram's oaken throne <antique>                     |  612000 br |\n" +
      "| 3. Mahogany dinner table of Castle Khan <antique>      |  850000 br |\n" +
      "| 4. Tin dagger of Slapping <enchanted>                  | 1200000 br |\n" +
      "| 5. Platinum dual-bladed long sword <enchanted>         | 1500000 br |\n" +
      "| 6. Lothar's adamantium full plate mail <enchanted>     | 2300000 br |\n" +
      "| 7. Two-edged broad sword named 'Painbringer' <unique>  | 2500000 br |\n" +
      "| 8. Quarterstaff of Supreme Wisdom <glowing> <unique>   | 2700000 br |\n" +
      "| 9. Ear of Ahmud (level 145) <unique>                   | 3700000 br |\n" +
      "+--------------------------------------------------------+------------+\n");
return 1;
}

//Changed || to && -- Rag 12.5.2004
hep(str) {
  if(str != "1" && str != "2" && str != "3" && str != "4" && str != "5" && str != "6" && str != "7" && str != "8" && str != "9") {
    write("Naglah says: 'Sorry, we don't have an item with that number.\n");
    return 1;
  }
  if(this_player()->query_coins() < 500000) {
    write("Naglah says: 'Sorry, you don't have enough bronze coins with you.\n");
    return 1;
  }
  else {
    write("Naglah apologies: 'I'm sorry, I cannot sell that to you.\n");
    return 1;
  }
}

  
