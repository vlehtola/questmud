start(object ob1, object arg) {
        object room1, arg1;
        room1 = ob1;
    arg1 = arg;
        call_out("search_end",5,room1, arg1);
}

query_search_ob() {
        return this_object();
}

search_end(object ob,string arg) {
object room2, ob2, ob1;
string arg2;
arg2 = arg;
ob1 = ob;
room2 = file_name(environment(this_player()));
ob2 = find_object(room2);
if(ob == ob2) {
        if(arg2) {
        write("You finished searching.\n");
        ob2->search_finished(arg2);
        destruct(this_object());
        return 1;
}
        write("You finished searching.\n");
                ob2->search_finished();
                destruct(this_object());
                return 1;
        }
        write("Your searching was interrupted.\n");
        destruct(this_object());
        return 1;
}

id(str) {
        return str == "search_ob";
}
