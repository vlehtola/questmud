object liv;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);
}

query_skills(str) {
        tell_object(liv, "Query: "+str+" ");
        if(str == "knuckless") {
          tell_object(liv, file_name(previous_object()));
        }
        tell_object(liv, "\n");
        return liv->query_skills(str);
}

end_shadow() {
        destruct(this_object());
        return 1;
}
