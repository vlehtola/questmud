inherit "obj/monster";

reset(arg) {
  object dagger, vest;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+28);
  set_name("demon raider");
  set_alt_name("demon");
  set_alias("raider");
  set_short("Red demon raider");
  set_long("The idle-looking demon is leaning against the wall. It is wearing a black\n" + 
           "furry vest, probably made from one of the dog demons roaming around the castle\n" + 
           "Though the demon might look very lazy when leaning the wall, it might still\n" + 
           "possess very quick reflexes when needed. Raider is observing its surroundings\n" + 
           "very carefully in the same time as chewing a toothpick in its small mouth.\n");
  set_al(-55);
  set_aggressive(0);
  set_resists("fire",55);
  set_skill_chance("kick", 80);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Demon raider frowns at you.\n";
    chat_str[1] = "Demon raider looks dreamily at its dagger.\n";
    chat_str[2] = "Demon raider strokes its furry vest.\n";
  }
  load_chat(3, chat_str);

  dagger = clone_object("/wizards/nalle/jerusalem/eq/knife2");
  move_object(dagger, this_object());
  init_command("wield dagger");
  
  vest = clone_object("/wizards/ahma/castle/eq/vest");
  move_object(vest, this_object());
  init_command("wear vest");
}