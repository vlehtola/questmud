object mage;

int run;

query_name() { return "Zadax"; }

string query_creator() { return "Rag"; }

string query_event_desc() { return
"Zadax arrives to a random room in the outworld.\n"+
"He banishes players and summons them to him.\n"+
"When he looses a shape in battle he teleports\n"+
"again. The event ends when he is killed or after 2\n"+
"hours. The members on the killparty get 7 QP's each.\n"; }

string query_mortal_desc() { return
"Zadax, the traveller between worlds, has once again found\n"+
"his way to this world. His magical energies disrupt the\n"+
"harmony of Deleria so you must help in killing him! He\n"+
"is known to teleport around the outworld.\n"; }

int query_limit() { return 3; }

string query_active() {
        if(run) return "Yes";
        return "No";
}

void run_event() {
        run = 1;
        mage = clone_object("/wizards/rag/events/teleport/zadax");
        move_object(mage,"/world/city/cs");
        mage->teleport(1);
        shout("Zadax shouts: \"Finally I have arrived to the world of Deleria!\"\n");
        shout("Talos shouts: \"No! Zadax's magic disturbs the magical balance of our world, he must be destroyed!\"\n");
        call_out("end_event",3600*2);
        return;
}

void end_event() {
        run = 0;
        shout("Talos shouts: \"Hooray! Our world is safe again! Zadax has left!\"\n");
        remove_call_out("end_event");
        call_out("des",1);
        return;
}

des() {
        if(mage) {
                destruct(mage);
        }
        return 1;
}

special() {
        if(run && mage) {
                move_object(this_player(),environment(mage));
        } else {
                write("Event not running or bugging.\n");
        }
}
