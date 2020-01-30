/* outmapille area entryt //Celtron */

#define VMAP "/room/out/outmap"
#define SAVEFILE "/data/road_save"

static string *entries;
mapping roads;

check_special_coords(int x, int y) {
  string map;
  object ob;

  // New road_save data structure -Nalle 22.05.2004
  if( entries[ "x" + x + "y" + y ] )
    {
     return entries[ "x" + x + "y" + y ];
    }

  // Special check
  if(x == 112 && y == 114) {
    map = "/wizards/celtron/cemetary/virtual_map";
    call_other(map, "loading_hc", 0);
    ob = find_object(map);
    if(ob) ob->move_living("south", 30, 5);
    return 0;
  }

  return 0;
}

// Altered for new data structure

void add_road(int x, int y, string mark) 
{
  if(!mark) return;

  if(strlen(mark) > 1) mark = mark[0 .. 0];

  if(!roads) roads = ([ ]);

  roads += ([ "x"+x+"y"+y : mark ]);

  VMAP->set_special_mark( x, y, mark );
  save_object(SAVEFILE);
}

// Altered for new data structure
status remove_road(int x, int y) 
{
  roads -= ([ "x" + x + "y" + y ]);
  return 0;
}

// Altered for new data structure

void reset_special_marks() 
{
  string *arr;
  int i, x, y;

  arr = m_indices( roads );

  for(i=0;i<sizeof(entries);i++) 
  {
    VMAP->set_special_mark(entries[i][0], entries[i][1], entries[i][3]);
  }

  for(i = 0; i < sizeof(arr); i++)
     {
      if( sscanf( arr[i], "x%dy%d", x, y) == 2 )
	{
	 VMAP->set_special_mark( x, y, roads[arr[i]] );
	}
     }
}

reset(mixed arg) {
  if(arg) return;
  /* input here area coordinates */
  /* format: x,y,room, special_mark */
  entries = ({
  ({ 120, 84, "/wizards/veron/areat/cotd/street1", "?", }),
  ({ 140,161, "/wizards/ahma/ice/rooms/101", "?", }),
  ({ 180,148, "/wizards/ahma/orc/forest/for01", "?", }),
  ({ 24, 112, "/wizards/veron/areat/golem/room1", "?", }),
  ({ 234, 122, "/wizards/aarrgh/nyxi/entrance", "?", }),
  ({ 143, 89, "/wizards/neophyte/areat/farm/room1", "?", }),
  ({ 60, 111, "/wizards/neophyte/forest/room1", "?", }),
  ({ 105, 79, "/wizards/torspo/areat/gnomes/entrance", "?", }),
  ({ 47, 136, "/wizards/irmeli/valley/entrance", "?", }),
  ({ 107, 73, "/wizards/torspo/areat/ogre/room1", "?", }),
  ({ 164, 67, "/wizards/siki/lizard/entrance", "?", }),
  ({ 56, 64, "/wizards/irmeli/bwp/entrance", "?", }),
  ({ 113, 89, "/wizards/celtron/field/entrance", "?", }),
  ({ 214, 131, "/world/hallway/hall5", "?", }),
  ({ 73, 142, "/wizards/shadow/Wolf/beach", "?", }),
  ({ 151, 108, "/wizards/grathlek/area1/entrance", "?", }),
  ({ 61, 121, "/wizards/irmeli/area2/entrance", "?", }),
  ({ 83, 144, "/wizards/walla/area/sgate", "#", }),
  ({ 156, 142, "/wizards/devil/area/huoneet/r1.c", "?", }),
  ({ 199, 134, "/wizards/celtron/maze/entrance", "?", }),
  ({ 130, 122, "/wizards/manta/hill/room1", "#", }),
  ({ 148, 148, "/wizards/bulut/forest/forest1", "?", }),
  ({ 114, 107, "/world/mine/path1", "?", }),
  ({ 212, 127, "/world/hallway/hall", "?", }),
  ({ 65, 117, "/wizards/bulut/forl/ulos", "?", }),
  ({ 65, 107, "/wizards/jenny/mehta/huoneet/jokupaikka", "?", }),
  ({ 94, 86, "/wizards/nalle/area/entrance", "?", }),
  ({ 238, 149, "/wizards/siki/forest/entrance", "?", }),
  ({ 147, 164, "/wizards/gynter/element/gateway", "?", }),
  ({ 165, 148, "/wizards/rag/elf/room1.c", "?", }),
  ({ 215, 126, "/wizards/gynter/darke/entrance", "?", }),
  ({ 115,148, "/wizards/luminarc/wizcastle/room0", "?", }),
  ({ 43, 106, "/guilds/fighter/ranger", "?", }),
  ({ 61, 87, "/guilds/mage/entrance", "?", }),
  ({ 163, 91, "/guilds/mage/navigator", "?", }),
  ({ 175, 104, "/guilds/abjurer/entrance", "?", }),
  ({ 59, 124, "/guilds/warlock/cathedral/entrance", "?", }),
  ({ 97, 129, "/wizards/jenny/linnake/huoneet/begin", "?", }),
  ({ 247, 76, "/wizards/rag/ruins/entrance", "?", }),
  ({ 175, 161, "/wizards/nalle/plateau/path01", "?", }),
  ({ 43, 79, "/wizards/moonstar/areas/valley/entrance", "?", }),
  ({ 35, 130, "/wizards/moonstar/areas/wasteland/room36", "?", }),
  ({ 57, 103, "/wizards/moonstar/areas/forest/town/begin", "?", }),
  ({ 45, 127, "/guilds/artists/entrance", "?", }),
  ({ 260, 117, "/wizards/proge/moraloth/enter", "?", }),
  ({ 120, 137, "/wizards/moonstar/areas/mosnotar/forest/begin", "?", }),
  ({ 207, 74, "/wizards/rimber/cave/room1", "?", }),

/* #### MULTIEXIT areas after this line #### */

  /* duranghom */
  ({ 95, 119, "/world/city/westgate", "#", }),
  ({ 99, 119, "/world/city/eastgate", "#", }),
  ({ 97, 120, "/world/city/northgate", "#", }),
  ({ 97, 118, "/world/city/southgate", "#", }),
  /* jerusalem */
  ({ 89, 95, "/wizards/nalle/jerusalem/ngate", "#", }),
  ({ 90, 94, "/wizards/nalle/jerusalem/egate", "#", }),
  ({ 88, 94, "/wizards/nalle/jerusalem/wgate", "#", }),
  ({ 89, 93, "/wizards/nalle/jerusalem/sgate", "#", }),
  /* duncan/neophyte island */
  ({ 84, 48, "/wizards/duncan/island/mainentrance", "?", }),
  /* neophyten castle */
  ({ 185, 133, "/wizards/neophyte/areat/castle/entrance", "#", }),
  ({ 186, 133, "/wizards/neophyte/areat/castle/entrance", "#", }),
  ({ 185, 132, "/wizards/neophyte/areat/castle/entrance", "#", }),
  ({ 186, 132, "/wizards/neophyte/areat/castle/entrance", "#", }),
  /* gnael castle */
  ({ 80, 72, "/wizards/jenny/gnael/huoneet/gate2", "#", }),
  ({ 79, 71, "/wizards/jenny/gnael/huoneet/gate1", "#", }),
  ({ 80, 70, "/wizards/jenny/gnael/huoneet/gate4", "#", }),
  ({ 81, 71, "/wizards/jenny/gnael/huoneet/gate3", "#", }),

  /* City of Asgroth */
  ({ 252,94, "/wizards/moonstar/areas/asgroth/room/wbridge", "#", }),
  ({ 253,95, "/wizards/moonstar/areas/asgroth/room/nbridge", "#", }),
  ({ 254,94, "/wizards/moonstar/areas/asgroth/room/ebridge", "#", }),

  });

  if(!restore_object(SAVEFILE))
    save_object(SAVEFILE);
}

/*
check_special_coords(int x, int y) {
  object ob;
  y = 199 - y;
  if(x == 60 && y == 88) {
    return "/wizards/neophyte/forest/room1";
  }
  if(x == 105 && y == 120) {
    return "/wizards/torspo/areat/gnomes/entrance";
  }
  if(x == 47 && y == 63) {
    return "/wizards/irmeli/valley/entrance";
  }
  if (x == 107 && y == 126) {
    return "/wizards/torspo/areat/ogre/room1";
  }
  if (x == 164 && y == 132) {
    return "/wizards/siki/lizard/entrance";
  }
  if (x == 56 && y == 135) {
    return "/wizards/irmeli/bwp/entrance";
  }
  if (x == 113 && y == 110) {
    return "/wizards/celtron/field/entrance";
  }
  if (x >= 185 && x <= 186 && y >= 66 && y <= 67) {
    return "/wizards/neophyte/castle/entrance";
  }
  if (x == 214 && y == 68) {
      return "/world/hallway/hall5";
  }
  if (x == 73 && y == 57) {
      return "/wizards/shadow/Wolf/beach";
  }
    if (x == 151 && y == 91) {
      return "/wizards/grathlek/area1/entrance";
    }
    if (x == 61 && y == 78) {
        return "/wizards/irmeli/area2/entrance";
    }
    if (x == 83 && y == 55) {
        return "/wizards/walla/area/sgate";
    }
    if (x == 199 && y == 65) {
        return "/wizards/celtron/maze/entrance";
    }

    if (x == 130 && y == 77) {
        return "/wizards/manta/hill/room1";
    }
    if (x == 148 && y == 51) {
      return "/wizards/bulut/forest/forest1";
    }
    if (x == 114 && y == 92) {
        return "/world/mine/path1";
    }
    if (x == 95 && y == 80) {
        return "/world/city/westgate";
    }
    if (x == 99 && y == 80) {
        return "/world/city/eastgate";
    }
    if (x == 97 && y == 79) {
        return "/world/city/northgate";
    }
    if (x == 97 && y == 81) {
        return "/world/city/southgate";
    }

    if (x == 89 && y == 104) {
        return "/wizards/nalle/jerusalem/ngate";
    }
    if (x == 90 && y == 105) {
        return "/wizards/nalle/jerusalem/egate";
    }
    if (x == 88 && y == 105) {
        return "/wizards/nalle/jerusalem/wgate";
    }
    if (x == 89 && y == 106) {
        return "/wizards/nalle/jerusalem/sgate";
    }


    if (x == 43 && y == 93) {
        return "/guilds/fighter/ranger";
    }
    if (x == 212 && y == 72) {
        return "/world/hallway/hall";
    }
    if (x == 65 && y == 82) {
        return "/wizards/bulut/forl/ulos";
    }
    if (x == 94 && y == 113) {
        return "/wizards/nalle/area/entrance";
    }
    if (x == 61 && y == 112) {
      return "/guilds/mage/entrance";
    }
    if (x == 163 && y == 108) {
      return "/guilds/mage/navigator";
    }
    if (x == 175 && y == 43) {
      return "/guilds/abjurer/entrance";
    }

    return 0;
}
*/
/*

Taalta voi kopioida vanhoja juttuja, jotka on poistettu kaytosta jostain
syysta.

  if (x == 148 && y == 34) {
      return "/wizards/gynter/element/gateway";
  }
    if (x == 114 && y == 112) {
      return "/wizards/bulut/cave/entrance";
    }

  if (x == 45 && y == 72) {
      return "/world/artist/entrance";
  }
  if (x == 100 && y == 151) {
      return "/wizards/irmeli/area4/entrance";
  }
  if (x == 38 && y == 77) {
      return "/wizards/morgoth/forest/room/forest4";
  }
  if (x == 269 && y == 141) {
        return "/wizards/morgoth/cannibal/room/path1";
  }
  if (x == 82 && y == 133) {
        return "/wizards/irmeli/pena/entrance";
  }

*/

