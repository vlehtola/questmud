inherit "obj/monster";
object ob1,ob2;
reset(arg) {

    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {

    set_level(20);
    set_name("female");
    set_alias("sailor");
    set_short("A female sailor walking on the street");
    set_long("She is walking on the street, searching for something maybe nearest pub.\n"+
             "She looks like a fat person and she smells quite bad. She is wearing a\n"+
             "dirty looking sailor suit.\n");
    set_gender(2);
    set_race("human");
    set_whimpy();
        }
    if(i>5) {

    set_level(30);
    set_name("man");
    set_alias("sailor");
    set_short("A drunk sailor talking dirty");
    set_long("This was once a great sea captain but now he is lost in the world of\n"+
             "alcohol. He looks quite faded and bad shaped for all those drinking.\n"+
             "He is constantly talking something about how great was he in one time.\n");
    set_gender(1);
    set_race("elf");
      }


    if(i>15) {

    set_level(40);
    set_name("traveller");
    set_alias("man");
    set_short("A traveller from distant seas");
    set_long("The traveller is searching for shops and pubs to browse. He is a sea\n"+
             "traveller and sailorman one of the kind. He looks dirty but strong with\n"+
             "all those years spended on distant seas.\n");
    set_gender(1);
    set_race("human");
      }

    if(i==0) {

    set_level(45);
    set_name("guard");
    set_alias("female");
    set_short("A guard watching for trouble makers");
    set_long("This guard is walking on the streets and watching for trouble makers.\n"+
             "He is authorized to jail any misbehavour sailor or traveller. He looks\n"+
             "quite sharp and strong. He is wearing a flags of street guardians.\n");
    set_gender(1);
    set_race("dwarf");
    set_follow(15,1);
 }
 ob2 = clone_object("/wizards/neophyte/city/eq/armour");
 move_object(ob2, this_object());
 ob1 = clone_object("/wizards/neophyte/city/eq/armour1");
 move_object(ob1, this_object());
 init_command("wear all");
 set_move_at_reset();
}
