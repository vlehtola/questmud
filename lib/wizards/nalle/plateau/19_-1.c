#define XAXLE 19
#define YAXLE -1

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

  add_exit("enter", AREAPATH+"huntershack");

  short_desc = "A wooden shack by the outskirts of the forest";
  long_desc =
"You've arrived to a wooden shack by the outskirts of the forest.\n"+ 
"Severed heads of wild animals have been attached to the walls,\n"+
"including bears and massive stags. This must be some hunter's cabin.\n"+
"There is also a small red doghouse behind the shack.\n";

 if(!monster) {
 monster = clone_object(AREAPATH+"monsters/hunterdog");
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

