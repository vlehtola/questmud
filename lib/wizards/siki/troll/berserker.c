inherit "world/guilds/guild";
inherit "room/room";

reset(arg) {
  object plaque,monster;
  if (!present("plaque")) {
    plaque = clone_object("world/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  if(!monster) {
  if(arg) return;
  monster = clone_object("/wizards/siki/troll/monsters/berserker");
 move_object(monster, this_object());
}
  add_exit("west","wizards/siki/troll/f19");
  short_desc = "The Berserkers training area";
  long_desc = "In the deep woods. The trees are growing extremely dense and it\n"+
              "almost impossible to move. The ground is full of marks of battle;\n"+
              "pieces of metals, bloodstains and even rotten bodyparts and bones.\n";

}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}

guild_long_name() {
    return guild_name();
}
guild_name() {
    return "Berserkers";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Fighters") < 10) {
        write("You must have completed the Fighters guild first.\n");
        return 0;
    }
    if (this_player()->query_guild_level("Barbarians") < 10) {
        write("You must have completed the Barbarians guild first.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([3:"berserk:30;"]);
  sk += ([6:"berserk:60;"]);
  sk += ([10:"fury:60;"]);
  if(lev == 2 && this_player()->query_level() < 10) return 0;
  return sk;
}

get_bonuses(level) {
  return "str 1 , con 1 , ";
}
get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(guild_name());
    skill = ([ ]);

    if (lvl) {
         guild_level = lvl;
         if (guild_level > 10) { guild_level = 10; }
    }
    if (!guild_level) {
        write("Bugged.. not a member\n");
        return 0;
    }
    if (guild_level >= 1) {
      skill += (["berserk":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["berserk":(int) 40]);
      skill += (["calm down":(int) 40]);
    }
    if (guild_level >= 3) {
      skill += (["berserk":(int) 60]);
      skill += (["calm down":(int) 60]);
      skill += (["rage":(int) 20]);
      skill += (["fury":(int) 20]);
      skill += (["charge rush":(int) 20]);
    }
    if (guild_level >= 4) {
      skill += (["berserk":(int) 60]);
      skill += (["calm down":(int) 80]);
      skill += (["rage":(int) 20]);
      skill += (["fury":(int) 30]);
    }
    if (guild_level >= 5) {
      skill += (["berserk":(int) 70]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 30]);
      skill += (["fury":(int) 50]);
      skill += (["charge rush":(int) 40]);
    }
    if (guild_level >= 6) {
      skill += (["berserk":(int) 80]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 40]);
      skill += (["fury":(int) 60]);
      skill += (["stun":(int) 50]);
    }
    if (guild_level >= 7) {
      skill += (["berserk":(int) 100]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 50]);
      skill += (["fury":(int) 60]);
      skill += (["stun":(int) 60]);
      skill += (["inner strength":(int) 70]);
      skill += (["charge rush":(int) 60]);
    }
    if (guild_level >= 8) {
      skill += (["berserk":(int) 100]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 60]);
      skill += (["fury":(int) 70]);
      skill += (["stun":(int) 70]);
    }
    if (guild_level >= 9) {
      skill += (["berserk":(int) 100]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 70]);
      skill += (["fury":(int) 80]);
      skill += (["stun":(int) 80]);
      skill += (["inner strength":(int) 80]);
      skill += (["charge rush":(int) 80]);
    }
    if (guild_level >= 10) {
      skill += (["berserk":(int) 100]);
      skill += (["calm down":(int) 100]);
      skill += (["rage":(int) 100]);
      skill += (["fury":(int) 100]);
      skill += (["stun":(int) 100]);
      skill += (["inner strength":(int) 100]);
      skill += (["charge rush":(int) 100]);
    }

    skill_num = m_indices(skill);
    skill_max = m_values(skill);
    if (how == 0) {
        while (i < sizeof(skill_max)) {
            if (skill_num[i] == num) {
                return skill_max[i];
            }
            i += 1;
        }  
    }
    if (how == 1) {
        return skill_max[num];
    }
    if (how == 2 || how == 3) {
        return skill_num[num];
    }
    if (how == 4) {
        return skill_max;
    }
}

