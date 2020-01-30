inherit "obj/monster";

reset(arg) {

    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {

    set_level(5);
    set_name("animal");
    set_alias("worm");
    set_short("A white ice-worm <frozen>");
    set_long("The animals living underground are without exception deformed. This worm is\n"+
             "white, it's missing its pigment. Ice-worms can be only found from these\n"+
             "caves. It's long and covered with ice almost frozen, lying on the ground\n"+
             "lifeless.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
    set_al(10);
        }
    if(i>5) {

    set_level(6);
    set_name("animal");
    set_alias("frog");
    set_short("An ice-frog trying to catch insects");
    set_long("The animals living underground are without exception deformed. The frog is\n"+
             "thin, because it's blind and therefore catching insects is hard for this\n"+
             "poor creature. It's white because it's covered with ice and snow, separating\n"+
             "from the regular green frogs.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
    set_al(20);
      }


    if(i>15) {

    set_level(7);
    set_name("animal");
    set_alias("spider");
    set_short("An ugly ice-spider with rudimented legs");
    set_long("The animals living underground are without exception deformed. The spiders\n"+
             "are known from their legs, these cave ice-spiders legs are rudimented.\n"+
             "This spider is unable to wieve a web, making the hunting of insects\n"+
             "impossible.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
    set_al(30);
      }

    if(i==0) {

    set_level(8);
    set_name("animal");
    set_alias("bat");
    set_short("An ice-bat with massive wings and sharp teeths");
    set_long("The animals living underground are without exception deformed. The bat has\n"+
             "massive wings and sharp teeths. The wings are covered with ice and snow, as\n"+
             "well as it's whole body. You can see it's sharp teeths glow from it's mouth.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
    set_al(40);
 }
}
