#define XAXLE 17
#define YAXLE 0

// A semivirtual environment, by Nalle

#define AREAPATH "wizards/nalle/plateau/"

inherit AREAPATH+"plateau_map";
inherit "room/room";

int entropia;
object monster;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  entropia=random(10);

if(file_size("/"+AREAPATH+(XAXLE-1)+"_"+(YAXLE+1)+".c")>0)
  add_exit("northwest", AREAPATH+(XAXLE-1)+"_"+(YAXLE+1));
if(file_size("/"+AREAPATH+(XAXLE)+"_"+(YAXLE+1)+".c")>0)
  add_exit("north", AREAPATH+(XAXLE)+"_"+(YAXLE+1));
if(file_size("/"+AREAPATH+(XAXLE+1)+"_"+(YAXLE+1)+".c")>0)
  add_exit("northeast", AREAPATH+(XAXLE+1)+"_"+(YAXLE+1));
if(file_size("/"+AREAPATH+(XAXLE-1)+"_"+(YAXLE)+".c")>0)
  add_exit("west", AREAPATH+(XAXLE-1)+"_"+(YAXLE));
if(file_size("/"+AREAPATH+(XAXLE+1)+"_"+(YAXLE)+".c")>0)
  add_exit("east", AREAPATH+(XAXLE+1)+"_"+(YAXLE));
if(file_size("/"+AREAPATH+(XAXLE+1)+"_"+(YAXLE-1)+".c")>0)
  add_exit("southeast", AREAPATH+(XAXLE+1)+"_"+(YAXLE-1));
if(file_size("/"+AREAPATH+(XAXLE)+"_"+(YAXLE-1)+".c")>0)
  add_exit("south", AREAPATH+(XAXLE)+"_"+(YAXLE-1));
if(file_size("/"+AREAPATH+(XAXLE-1)+"_"+(YAXLE-1)+".c")>0)
  add_exit("southwest", AREAPATH+(XAXLE-1)+"_"+(YAXLE-1));

  short_desc = "In a forest";
 if(entropia<=2)
  long_desc =
"You are in a forest, where the largest trees seem to have been\n"+
"cut for lumber, large tree stumps have been left to rot where the\n"+ 
"trees used to be. Smaller trees have started to grow here recently\n"+
"and should you return in a few decades this should look like a real\n"+
"forest then.\n";
 else if(entropia<=5)
  long_desc =
"Pine trees are growing here very densely, hardly letting the sunlight\n"+
"through the thick cover of their branches. The soil is a bit wet here\n"+
"and emits the pleasant smell swamps sometimes do.\n";
 else if(entropia<=7)
  long_desc =
"A very dense part of the forest, murky and dark. Your feet sink quite\n"+
"bit into the swamp and moving is cumbersome. The pine trees here seem\n"+
"to be rotting and are generally not in a very good shape.\n";
 else if(entropia<=9)
  long_desc =
"This is a small cliff in the middle of the forest-like area. A small\n"+
"stream runs down the hill here, providing animals with water to drink\n"+ 
"and undeniably adding to the idyllic feeling of the location. This\n"+
"seems like the sort of area where bears might enjoy living, so beware.\n";

 if(!monster)
 if(entropia<1) {
 monster = clone_object(AREAPATH+"monsters/moose");
 move_object(monster, this_object());
                }
 else if(entropia<3) {
 monster = clone_object(AREAPATH+"monsters/owl");
 move_object(monster, this_object());
                     }
 else if(entropia<8) {
 monster = clone_object(AREAPATH+"monsters/stag");
 move_object(monster, this_object());
                     }
 else if(entropia<=9) {
 monster = clone_object(AREAPATH+"monsters/bear");
 move_object(monster, this_object());
                     }
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {  
if (arg) return 0;
drawmap(XAXLE, YAXLE);
return 1;  
}  

