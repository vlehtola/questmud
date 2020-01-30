inherit "/obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  object weapon;
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(15);
  set_level(15+i);
  set_alias("elf");
  set_name("worker");
  set_short("A dark elf worker repairing the road to the city");
  set_long("The workers are poor, but hard workers, although they work for free.\n"+
           "Workers in the dark elf society are compared to the slaves, in human\n"+
           "society. He is thin, in bad condition, almost half-dead, looking like a\n"+
           "skeleton. His job is to keep the road to the city in perfect condition.\n");

  set_gender(1);
  set_race("dark elf");
  set_al(30);

  weapon = clone_object("/wizards/gynter/darke/eq/hammer.c");
  move_object(weapon, this_object());
  init_command("wield warhammer");

  if (!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "Worker says: 'I don't feel good, but I must work now.'\n";
    chat_str[1] = "As the worker swings his warhammer to the ground, the ground shakes a bit.\n";
  }
  if (!a_chat_str) {
    a_chat_str = allocate(1);
    a_chat_str[0] = "Worker says: 'I don't wanna die!'\n";
  }
  load_chat(15, chat_str);
  load_a_chat(45, a_chat_str);

 }
