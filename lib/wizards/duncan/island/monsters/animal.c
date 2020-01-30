inherit "obj/monster";

reset(arg) {

    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {

    set_level(5);
    set_name("animal");
    set_alias("crayfish");
    set_short("A tiny crayfish with sharp pincers");
    set_long("A red crayfish is tiny, but its sharp pincers make it dangerous in every\n"+
             "way. Every adventurer and animal should be afraid of it. A thick, red\n"+
             "shell covers the crayfish from enemies.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
        }
    if(i>5) {

    set_level(10);
    set_name("animal");
    set_alias("turtle");
    set_short("An old turtle crawling in the sand");
    set_long("An old turtle is crawling slowly, but definitely towards the drier land.\n"+
             "A strong shell, shield-shaped, is covering the turtle from every direction.\n"+
             "The turtle can pull its head and limbs inside the shell.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
      }


    if(i>15) {

    set_level(15);
    set_name("animal");
    set_alias("eagle");
    set_short("A white-tailed eagle");
    set_long("A huge brown, white-tailed eagle has landed on the beach. Its big, bushy\n"+
             "wings are full of brown and white quills. Its wingspan must be over five\n"+
             "meters. It's waiting for stronger wind, to take to the air.\n");
    set_animal(1);
    set_aggressive(1);
    set_gender(0);
      }

    if(i==0) {

    set_level(20);
    set_name("animal");
    set_alias("fisherman");
    set_short("A fisherman standing on the beach, observing the horizon");
    set_long("A fisherman is observing the horizon, trying to observe sailors in distress.\n"+
             "He is quite tall, thin and skinny, usual looking fisherman with thick beard\n"+
             "and pipe in his mouth.\n");
    set_race("human");
    set_aggressive(0);
    set_gender(1);
 }
}
