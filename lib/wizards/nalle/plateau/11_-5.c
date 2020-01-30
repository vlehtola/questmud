#define XAXLE 11
#define YAXLE -5

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

  short_desc = "A verdant plateau";
 if(entropia<=1)
  long_desc =
"You are standing on a verdant plateau that covered with miscellaneous\n"+
"undergrowth and a few trees here and there. You notice some raspberry\n"+ 
"bushes that reach up to your elbows and a good deal of other vegetation\n"+
"which you do not recognize. There are small trails between the bushes\n"+
"and it seems like they are harvested for berries.\n";
 else if(entropia<=3)
  long_desc =
"Bushes surround you utterly, and moving is cumbersome here. You spot\n"+
"some blueberry bushes here, amongst other things. Some pine trees\n"+ 
"also seem to try their luck growing through the undergrowth here,\n"+
"not with great success though. Most trees here seem to be under a\n"+
"few meters tall.\n";
 else if(entropia<=5)
  long_desc =
"This part of the plateau is a bit easier to walk around in, as it\n"+
"is mainly covered only in hay and grass, with the exception of an\n"+ 
"elm tree or two. You can see the whole plateau from here, as this\n"+
"location seems somewhat elevated. You notice a few rabbits from the\n"+
"corner of your eye.\n";
 else if(entropia<=7)
  long_desc =
"A great elm tree has taken root in this opening. It looks rather\n"+
"majestic in contrast with the withering pines that weave under the\n"+ 
"wind's soft caress. Otherwise this part of the plateau only has\n"+
"some smaller blueberry bush concentrations in addition to the\n"+
"omnipresent hay.\n";
 else if(entropia<=8)
  long_desc =
"There is a small pond here amongst the vegetation, unfortunately\n"+
"the water so saturated with algae that the thought of it being\n"+ 
"potable does not linger in your mind for the briefest moment.\n"+
"Small critters scurry about in the undergrowth, carrying on with\n"+
"their usual routines.\n";
 else if(entropia<=9)
  long_desc =
"You've arrived to a concentration of large rocks, that have\n"+
"probably tumbled down from the mountain top centuries ago. Their\n"+ 
"crevices seem to have provided birds with adequate locations for\n"+
"their nests and you can't help noticing a few swallows' nests\n"+
"meticulously built on top of a particularly large rock-formation.\n";

 if(!monster)
 if(entropia<1) {
 monster = clone_object(AREAPATH+"monsters/moose");
 move_object(monster, this_object());
                }
 else if(entropia<3) {
 monster = clone_object(AREAPATH+"monsters/deer");
 move_object(monster, this_object());
                     }
 else if(entropia<4) {
 monster = clone_object(AREAPATH+"monsters/boar");
 move_object(monster, this_object());
                     }
 else if(entropia==9) {
 monster = clone_object(AREAPATH+"monsters/swallow");
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

