get_time() {
    return 1;
}
ep_cost() { return 1; }
query_type() { return "neutral"; }

resolve_skill(target) {
    if(target->query_bleeding()) {
        target->end_bleeding();
}
 }
