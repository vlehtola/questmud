#define XAXLE 9
#define YAXLE -3

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

  add_exit("enter", AREAPATH+"hut3");

  short_desc = "A wooden shack";
  long_desc =
"A small shack has been erected to this location, it even has a\n"+
"small chimney protruding from the roof, with smoke slowly drawing\n"+ 
"a black streak into the sky.\n";

 if(!monster)
 if(entropia<4) {
 monster = clone_object(AREAPATH+"monsters/dog");
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

