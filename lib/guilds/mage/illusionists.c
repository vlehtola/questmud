/* Fixed joining requirements, works with abjurers now
   The guild was 'abjurers' but actually it's 'abjurer'
   -- Rag 18.4.2004 */

inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("east","/wizards/nalle/area/tower3");
  add_exit("north", "/guilds/mage/electric_adept");
  short_desc = "The illusionists guild";
  long_desc = "This room is the illusionist training area.\n"+
"Illusionists train abilities to counter enemy spellcasting and\n"+
"create illusionary effects with the Essence.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}
guild_name() {
    return "Illusionists";
}

check_joining_rec() {
    if (this_player()->query_guild_level("apprentice mages") != 20 &&
        this_player()->query_guild_level("abjurer") < "/guilds/abjurer/abjurers"->guild_max_level()) {
        write("Must have completed the Appretice Mage or Abjurer guild first.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
  return "int 2 , con -1 , ";
}
/*
cast fire: 100%
knowledge of heat 100%
*/
skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast illusion":(int) 30]);
      skill += (["counter spell":(int) 10]);
    }
    if (guild_level >= 2) {
      skill += (["cast illusion":(int) 35]);
      skill += (["counter spell":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["cast illusion":(int) 40]);
      skill += (["counter spell":(int) 30]);
      skill += (["reflect spell":(int) 10]);
    }
    if (guild_level >= 4) {
      skill += (["cast illusion":(int) 50]);
      skill += (["counter spell":(int) 40]);
      skill += (["reflect spell":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["cast illusion":(int) 60]);
      skill += (["counter spell":(int) 50]);
      skill += (["reflect spell":(int) 30]);
    }
    if (guild_level >= 6) {
      skill += (["cast illusion":(int) 70]);
      skill += (["counter spell":(int) 55]);
      skill += (["reflect spell":(int) 50]);
      skill += (["elusive spellcasting":(int) 10]);
    }
    if (guild_level >= 7) {
      skill += (["cast illusion":(int) 80]);
      skill += (["counter spell":(int) 60]);
      skill += (["reflect spell":(int) 55]);
      skill += (["elusive spellcasting":(int) 30]);
    }
    if (guild_level >= 8) {
      skill += (["cast illusion":(int) 100]);
      skill += (["counter spell":(int) 65]);
      skill += (["reflect spell":(int) 60]);
      skill += (["elusive spellcasting":(int) 50]);
    }
    if (guild_level >= 9) {
      skill += (["counter spell":(int) 70]);
      skill += (["reflect spell":(int) 65]);
      skill += (["elusive spellcasting":(int) 70]);
    }
    if (guild_level >= 10) {
      skill += (["cast illusion":(int) 100]);
      skill += (["counter spell":(int) 100]);
      skill += (["reflect spell":(int) 100]);
      skill += (["elusive spellcasting":(int) 100]);
    }
return skill;
}
