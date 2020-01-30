inherit "obj/monster";
int wandering;
string wander_area;
int is_wandering;

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
    set_level(20);
    set_name("monster");
    set_alias("test");
    set_short("A wandering test monster");
    set_long("A test mob!.\n");
    set_gender(2);
    set_race("human");
    set_wandering("workroom", 10);
}

wander() {
    int n,i;
    string *dirs;
    string dir;
    string darea;
    dirs = environment(this_object())->query_dest_dir();
    for(i = 0;i < sizeof(dirs);i++) {
                if(environment(this_object())->query_valid_dir(dirs[i])) {
                        dir = random(dirs[i]);
                }
        }
   tell_environment(this_object(),"Dir is :"+dir+" and the area there is '"+darea+"' and i can only go '"+wander_area+"' areas\n");
   call_out("random_move",wandering);
}

set_wandering(string str,int i) {
        wander_area = str;
        wandering = i;
        is_wandering = 1;
        wander();
}

