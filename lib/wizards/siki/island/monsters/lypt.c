inherit "obj/monster";


int q;


reset(arg) {

object weapon, armour;
string chat_str;
    ::reset(arg);
    if(arg) { return; }

    q = 0;

    set_level(28+random(3));
    set_name("lypt");
    set_alias("guard");
    set_alt_alias("giant guard");
    set_race("giant");
    set_short("Lypt, the giant commander of the mines");
    set_long("A messy looking giant who is in charge of the mines. He gives all the orders\n"+
             "and the guards enforce them. His small beard is dirty, seems like there is some\n"+
             "food on it.\n");

    set_al(0);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);

    if (q==0) {
     if (!chat_str) {
      chat_str = allocate(2);
      chat_str[0] = "Lypt looks miserable and booms 'Heinr will soon kill me\n"+
                    "if the stupid slaves will not find gold.'\n";
      chat_str[1] = "Lypt examines the papers in anger and curses.\n";
                 
     }
     load_chat(5, chat_str);
    }
    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");
    armour = clone_object("/wizards/siki/island/eq/chainmail");
    move_object(armour,this_object());
    init_command("wear mail");

}
catch_tell(str) {
   string tmp1,tmp2, chat_str;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives gold %s.", tmp1, tmp2) == 2) {
    ob = present("gold", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    destruct(ob);
    write("Lypt booms loudly 'GOLD! YOU FOUND GOLD! Thank you so much!'\n");
    this_player()->set_quest("Giant Mine", 4);
    q = 1;
    chat_str = allocate(2);
    chat_str[0] = "Lypt looks at a piece of gold and smiles.\n";
    chat_str[1] = "Lypt booms 'I'm so happy! Heinr will be pleased to hear that I\n"+
                  "found some gold.'\n";
    load_chat(5, chat_str);
   }
}
 }
