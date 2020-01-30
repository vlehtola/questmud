#define AREAPATH "wizards/nalle/rebirth/"

inherit AREAPATH+"rb_map";
inherit "room/room";

int entropia;
object monster;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  entropia=random(10);
  add_exit("northeast", AREAPATH+"path05");
  add_exit("southwest", AREAPATH+"b8");
  add_exit("southwest", AREAPATH+"b8");
  add_exit("south", AREAPATH+"b9");
  add_exit("southeast", AREAPATH+"b10");
  short_desc = "A verdant plateau";
 if(entropia<=2)
  long_desc =
"You are standing on a verdant plateau that covered with miscellaneous\n"+
"undergrowth and a few trees here and there. You notice some raspberry\n"+ 
"bushes that reach up to your elbows and a good deal of other vegetation\n"+
"which you do not recognize. There are small trails between the bushes\n"+
"and it seems like they are harvested for berries.\n";
 else if(entropia<=5)
  long_desc =
"Bushes surround you utterly, and moving is cumbersome here. You spot\n"+
"some blueberry bushes here, amongst other things. Some pine trees\n"+ 
"also seem to try their luck growing through the undergrowth here,\n"+
"not with great success though. Most trees here seem to be under a\n"+
"few meters tall.\n";
 else if(entropia<=7)
  long_desc =
"This part of the plateau is a bit easier to walk around in, as it\n"+
"is mainly covered only in hay and grass, with the exception of an\n"+ 
"elm tree or two. You can see the whole plateau from here, as this\n"+
"location seems somewhat elevated. You notice a few rabbits from the\n"+
"corner of your eye.\n";
 else if(entropia<=9)
  long_desc =
"A great elm tree has taken root in this opening. It looks rather\n"+
"majestic in contrast with the withering pines that weave under the\n"+ 
"wind's soft caress. Otherwise this part of the plateau only has\n"+
"some smaller blueberry bush- concentrations in addition to the\n"+
"omnipresent hay.\n";

 if(!monster)
 if(entropia<2) {
 monster = clone_object(AREAPATH+"monsters/moose");
 move_object(monster, this_object());
                }
 else if(entropia<4) {
 monster = clone_object(AREAPATH+"monsters/deer");
 move_object(monster, this_object());
                     }
 else if(entropia<5) {
 monster = clone_object(AREAPATH+"monsters/boar");
 move_object(monster, this_object());
                     }
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {  
    if (arg) {
        return 0;
    }

  if(this_player()->query_terminal()) 
  write("\n"+cmap_a+"\n"); else 
  write("\n"+map_a+"\n");  
  
   return 1;  
}  
