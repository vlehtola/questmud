#define SP_COST 100
get_time(str) {
  return random(4)+2;
}
ep_cost() { return 1; }
query_type() { return "neutral"; }


resolve_skill(str) {
int time;
object ob;
    if(this_player()->query_sp() < SP_COST) {
                write("You don't have enough mental energy to complete this skill.\n");
                return 1;
        }
        time = this_player()->query_skills("mental light")*3;
        time += this_player()->query_wis()+this_player()->query_int();
        write("You create a orb of light.\n");
        ob = clone_object("/guilds/psi/specials/light_orb");
        move_object(ob, this_player());
        ob->start(time);
        this_player()->reduce_sp(SP_COST);
}

fail_skill(str) {

    if(random(100) < this_player()->query_skills("mental light")) {
        resolve_skill(str);
        return 1;
    }

    write("You lose your concentration and fail the skill.\n");
return 1;
}
