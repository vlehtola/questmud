inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(4);
  set_level(15+i*15);
  set_name("trainee");
  set_alias("elf");
  if (i == 0) {
    set_short("A small trainee");
    set_long("This is one of the many young dark elf trainees.\n"+
             "They are the best of the best and thus earned the\n"+
             "right to train for the Dark Elf Army.\n");
  } else if (i == 1) {
    set_short("A dark elf trainee");
    set_long("This is one of the many young dark elf trainees.\n"+
             "They are the best of the best and thus earned the\n"+
             "right to train for the Dark Elf Army.\n");
  } else if (i == 2) {
    set_short("A dark elf warrior");
    set_name("warrior");
    set_long("This is one of the many young dark elf warriors.\n"+
             "They are the best of the best and thus earned the\n"+
             "right to train the Dark Elf trainees.\n");
  } else if (i >= 3) {
    set_short("A dark elf trainer");
    set_name("trainer");
    set_long("This is one of the mighty trainers. Don't fuck with him.\n");
  }
//tuned by Moonstar 3.10.2004
   set_skills("blades", 100);
   set_skills("slash", 80);
   set_skills("two weapons combat", 100);
   set_skills("critical",100);
   set_skills("doublehit", 100);
   set_skills("find weakness", 80);
   set_skills("stun",100);
   set_skills("double strike",100);
   set_skills("disarm",70);
   set_skill_chance("disarm", 70);
   set_skills("find weakness",80);
   set_skills("reflect spell",15);
   set_skills("strike",100);
   set_skill_chance("strike", 50);
  set_race("dark elf");
  set_gender(1);
}
