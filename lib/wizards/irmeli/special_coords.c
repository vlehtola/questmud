check_special_coords(x,y) {
  object ob;
  if(x == 112 && y == 85) {
    call_other("/wizards/celtron/cemetary/virtual_map", "loading_hc", 0);
    ob = find_object("/wizards/celtron/cemetary/virtual_map");
    if(ob) ob->move_living("south", 30, 5);
    return 1;
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
/*  if (x == 148 && y == 34) {
      return "/wizards/gynter/element/gateway";
  } */
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
/*    if (x == 114 && y == 112) {
      return "/wizards/bulut/cave/entrance";
    } */
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

/*

Taalta voi kopioida vanhoja juttuja, jotka on poistettu kaytosta jostain
syysta.

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
  if (x == 207 && y == 128) {
        return "/wizards/aarrgh/nyxi/entrance";
  }

*/

