#define XAXLE 15
#define YAXLE -6

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

  short_desc = "A trail leading further up the mountain";
  long_desc =
"This dirt path leads further up the mountain. You try to peer up\n"+
"the slope to see where it leads and spot the vague silhouette\n"+ 
"of some sort of castle or perhaps, tower. A well tended garden\n"+
"lies to the east and to the west.\n";
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

