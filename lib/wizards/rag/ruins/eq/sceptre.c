#define SD "/wizards/rag/ruins/sceptre_d"
#define TP this_player()

inherit "obj/weapon";
int times;

init() {
        add_action("swing","swing");
        ::init();
}

start() {
        set_class(9);
        set_sub_type("staff");
        set_name("sceptre");
        set_short("Sceptre of Chaos");
        set_long("This Sceptre is made from some black metal. You get the feeling that it is not\n"+
                 "from this world. It feels cold to the touch, almost as if it would drain your\n"+
                 "essence. It is decorated with some dark jewels and ancient runes. You can\n"+
                 "understand only one sentence: 'Swing the Sceptre and enter the Darkness'\n");

        set_slayer("human");
}

swing(str) {
        if(!str) { 
                write("Swing what?\n");
                return;
        }
        if(present(str) != this_object()) return;
        
        if(!(this_object() == TP->query_right_weapon() || this_object() == TP->query_left_weapon())) {
                write("You must wield the Sceptre to use it's powers.\n");
                return 1;
        }
        
        write("You swing the Sceptre of Chaos and you feel evil forces flowing to you.\n");
        say(TP->query_name()+" swings the Sceptre of Chaos!\n");
        TP->add_alignment(-5);

        if(SD->query_use(this_player()->query_name()) > 2) {
                write("You feel that you do not possess enough power to handle the Sceptre.\n");
                return 1;
        }
        
        write("The chaotic Sceptre replenishes your energy but the evil forces steal a\n"+
                "part of you life force and humanity!\n");
        
        TP->set_sp(TP->query_sp()*2+random(TP->query_max_sp()));
        if(TP->query_sp() > TP->query_max_sp()) TP->set_sp(TP->query_max_sp());
        
        TP->set_hp(TP->query_hp()*4/5);
        SD->add_use(this_player()->query_name());
        return 1;
}       

check_weapon_break() { return 1; }
