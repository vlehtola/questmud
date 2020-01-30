string asker,target;
object asker_ob, target_ob;

init() {
    add_action("accept", "accept");
}

int accept(string str);
void timeout_counter();
void timeout_end(); 
void set_values(string asker_t, string target_t);

id(str) { return str == "proposal_object"; }

/*************************/

void set_values(string asker_t, string target_t) {

asker=asker_t; target=target_t;
asker_ob=find_player(asker);
target_ob=find_player(target);

tell_object(target_ob,asker_ob->query_name()+
        " proposed to marry you.\n");

timeout_counter();
}

/*************************/

int accept(string str) {


if (str != "proposal") return 0; 

tell_object(target_ob,"You accept the proposal.\n");
tell_object(target_ob,"You are now married to "+
        asker_ob->query_name()+".\n");
tell_object(find_player(asker), 
    target_ob->query_name()+" accepted your proposal.\n");
tell_object(find_player(asker),"You are now married to "+       
    target_ob->query_name()+"\n");

// Kukat
move_object(
clone_object("/wizards/nalle/marriage/flowers"),asker_ob);
tell_object(asker_ob,
"A lovely bouquet of flowers drops onto your lap from the heavens.\n"); 
say("A bouquet of flowers falls down from "+
"the heavens onto "+asker_ob->query_name()+"'s lap!\n",asker_ob);

move_object(
clone_object("/wizards/nalle/marriage/flowers"),target_ob);
tell_object(target_ob,
"A lovely bouquet of flowers drops onto your lap from the heavens.\n"); 
say("A bouquet of flowers falls down from "+
"the heavens onto "+target_ob->query_name()+"'s lap!\n",target_ob);

tell_room(environment(asker_ob),asker_ob->query_name()+" and "
+target_ob->query_name()+" got married.\n");

target_ob->set_married("1 "+asker_ob->query_name());
asker_ob->set_married("1 "+target_ob->query_name());

destruct(this_object());
return 1;
}

void timeout_counter() {
tell_object(target_ob,"You have 75 seconds to 'accept proposal'.\n");
call_out("timeout_end",75);
}

void timeout_end() { 
tell_object(target_ob,
     "You did not accept "+capitalize(asker)+"'s proposal.\n");

tell_object(find_player(asker), 
    target_ob->query_name()+" did not accept your proposal.\n");

destruct(this_object()); 
}

/*************************/

