object ob,spessu;
string target,user;
int damage,percent;

        hit_func(str) {
        this_player()->using_skill(10);
        call_out("skill",10,str);
        }

//
// here begins the skill code.
//

skill(str) {

        if(this_player()->query_ghost()) return 1;


        sscanf(str,"%s,%s",user,target);

        if(target =="no_target") {
                if("/daemons/target_daemon"->get_target())
                        target = "/daemons/target_daemon"->get_target();
                }

        // jos EI bludia k�dess� ei pysty ly�m��n
        if(this_player()->query_weapon_type() != 4) {
                write("You will never be able to SLAM anyone with that weapon!\n");
                destruct(this_object());
                return 1;
        }

 if(present(target,environment(this_player()))) {

        percent=this_player()->query_skill("slam");

        ob = (present(target,environment(this_player())));
/*
Troll SLAMS its bludgeon quickly at you, and manages to CRUSH you badly.
Troll continues its movement and SLAMS you again before you can react!
Troll manages to gain additional FORCE into his attack and
neatly SLAMS its bludgeon deep into your head, causing TERRIBLE PAIN! You can hear your bones CRACK!
*/

        if(percent / 2 + (percent / 3) + random(100) < 100) {fail();return 1;}

//      write();

        tell_object(ob,
                capitalize(this_player()->query_name())+" SLAMS its bludgeon quickly at you, and manages to CRUSH you badly.\n"+
                capitalize(this_player()->query_name())+" continues its movement and SLAMS you again before you can react!\n"+
                capitalize(this_player()->query_name())+" manages to gain additional FORCE into his attack and neatly SLAMS its bludgeon deep into your\n"+
                "head, causing TERRIBLE PAIN! You can hear your bones CRACK!\n");
        say(capitalize(this_player()->query_name())+" SLAMS its bludgeon quickly at "+ob->query_name()+", and manages to CRUSH "+ob->query_objective()+" badly.\n"+
            capitalize(this_player()->query_name())+" continues its movement and SLAMS "+ob->query_objective()+" again before "+ob->query_pronoun()+" can react!\n"+
            capitalize(this_player()->query_name())+" manages to gain additional FORCE into his attack and neatly SLAMS its bludgeon deep into "+ob->query_name()+"'s head,\n"+
            "causing TERRIBLE PAIN! You can hear "+ob->query_name()+"'s bones CRACK!\n",ob);

        damage=percent*3+random(2000);
        ob->hit_player(damage);
        this_player()->reduce_ep(damage/10);
        destruct(this_object());
        return 1;
        }
        write("Slam who?\n");
        destruct(this_object());
        }

fail() {

        present(("gloves"),this_player())->rem();

        write("You fail to slam "+capitalize(ob->query_name())+"!\n");
        ob->hit_player(0);
        destruct(this_object());
}

tired() {
        write("You are too tired!\n");
        ob->hit_player(0);
        destruct(this_object());
}

break_skill() {
remove_call_out("skill");
destruct(this_object());
}
        ob->hit_player(0);
        destruct(this_object());


break_skill() {
remove_call_out("skill");
destruct(this_object());
}
