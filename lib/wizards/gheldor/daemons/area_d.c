/**********************************************************************************
 *   AD - Area Daemon, /doc/examples/area_d.c
 *   Copyright (C) 2000
 *
 * AUTHORS FILE:
 *   This file attempts to remember all contributors to the AD
 *   developement. Names can be only added this file, no name
 *   should never be removed. This file must be included into all
 *   distributions of AD and derived works.
 *
 *   This source is free; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 **********************************************************************************
 *   23.09.00 (Gheldor) - Created the base (v1.0b) of AD.
 *   23.09.00 (Gheldor) - Added the GNU disclaimer.
 *   23.09.00 (Gheldor) - Created the dox for the usage of this file.
 *********************************************************************************
 * Usage: You need to make a room "/wizards/yourname/yourarea/room_0_0.c" which has
 *        this kind of code inzide it...
 * --- room_0_0.c ---
 * inherit "room/room"; <- This inheritances the base room
 * #include "/wizards/gheldor/include/default.h" <- This include gets the 'AREA_D'
 * reset(arg) {
 * if(arg) return;
 * short_desc = "Inside the Mystical Forest";
 * long_desc = AREA_D->get_long("mforest");
 * set_light(1);
 * AREA_D->get_monsters("mforest",4,this_object());
 * AREA_D->get_exits(this_object());
 *}
 * --- room_0_0.c ---
 * Then make other rooms with the style room_x_y.c and the rest should be done by
 * it's own, due this daemon roxor's aLoT! ;)))
 * ++Gheldor
 *********************************************************************************/


mapping descs;
mapping monsters;

#define NPC(ob,where) present(ob,where)->query_npc();
#define DEBUG "gheldor"

void reset() {

  monsters = ([
    "mforest":({ "/wizards/gheldor/area1/monster1.c", }),
  ]);


  descs = ([
    "mforest":({

      "As you look closely around you notice some movement and\n"+
      "alot of red eyes gleaming around you and watching your every\n"+
      "movement and possible mistake so they could attack you!\n",

      "The deeper you look into the forest, the less you see.\n"+
      "The forest has the most weird trees that you have ever seen\n"+
      "on your journeys on the world. The trees change their shape\n"+
      "as you turn your eyes from them, but also they are blue as their colour!\n",

      "The hallucination is known by a small group of people, but you realize\n"+
      "that this must be one, because you aren't drunk and all kind of weird things\n"+
      "is happening all over the forest, but in same time it doesn't feel like it\n"+
      "would exist in here and it would be a trick for mind, but a magical one.",

      "The athmosphere is getting warmer and creepyer, due the temperature is still\n"+
      "bouncing up and down as something moves inside the room.\n"+
      "There can be sensed hostility around the place.\n",

      "The temperature is bouncing again, as you step another footstep forward, it's\n"+
      "cold, and as you step the third step the temperature is much on the positive\n"+
      "side. There must be some battle against the cold and warm like good and evil\n"+
      "has often against each other, maybe these two things are connected to each other?\n",

    }),

    "next_area":({

      "Next areas long description 1...\n",

      "Next areas long description 2...\n",

      // And so on...
    }),

  ]);
}

string get_long(string str) {
  if(!descs[str]) {
    tell_object(find_player("gheldor"),"AREA DAEMON CAN'T FIND ["+str+"] FROM THE LIST!\n");
    return "AREA DAEMON ERROR:\n\tCan't find that area.\n";
  }
  return descs[str][random(sizeof(descs[str]))];
}

void get_monster(string str,int amount,object ob) {
  string monster;
  int i;

  object *room;
  if(!monsters[str]) {
    tell_object(find_player("gheldor"),"AREA DAEMON CAN'T FIND ["+str+"] FROM THE LIST!\n");
    return;
  }
  room = all_inventory(ob);
  for(i=0;i<sizeof(room);i++) if(present(room[i]->query_name(),ob)->query_npc()) return;

  monster = monsters[str][random(sizeof(descs[str]))];

  if(!present(monster->query_name(),previous_object()))
    for(i=0;i<amount;i++) {
       monster = monsters[str][random(sizeof(descs[str]))];
       move_object(clone_object(monster),previous_object());
    }


  return;
}

string get_exits(object ob) {
  string dir,dest;
  int x,y,X,Y,i;
  sscanf(file_name(ob),"%s/room_%d_%d",dir,X,Y);
  tell_object(find_player(DEBUG),"Filename "+dir+"/room_"+X+"_"+Y+" found!\n");
  for(i=0;i<4;i++) {
     if(!i) {
       x= X+1;
       y = Y;
       dest = dir+"/room_"+x+"_"+y+".c";
       if(file_size(dest) > 10){
         ob->add_exit("east",dest);
         tell_object(find_player(DEBUG),"Filename "+dir+"/room_"+X+"_"+Y+" added dir to east!\n");
       }
     }
     if(i == 1) {
       x = X-1;
       y = Y;
       dest = dir+"/room_"+x+"_"+y+".c";
       if(file_size(dest) > 10) ob->add_exit("east",dest);
     }
     if(i == 2) {
       x = X;
       y = Y+1;
       dest = dir+"/room_"+x+"_"+y+".c";
       if(file_size(dest) > 10) ob->add_exit("east",dest);
     }
     if(i == 3) {
       x = X;
       y = Y-1;
       dest = dir+"/room_"+x+"_"+y+".c";
       if(file_size(dest) > 10) ob->add_exit("east",dest);
     }
 }
}

