#include <string>
#include <nlohmann/json.hpp>

#include "inja.hpp"

using namespace inja;
using json = nlohmann::json;

using std::cout;
using std::endl;
using std::string;

int main() {
    json data;

    data["name"] = "world";
    cout << endl;

    string test;
    test = render("Hello {{ name }}!", data);
    cout << test << endl;

    render_to(cout, "Hello {{ name }}!", data);
    cout << endl;

    Environment env;

    string result;
    result = env.render("Hello {{ name }} again!", data);
    cout << result << endl;;

    // Template temp = env.parse_template("./some_template.txt");

    data["name"] = "Inja";
    data["neighbor"] = "Peter";
    data["guests"] = {"Jeff", "Tom", "Patrick"};
    data["time"]["start"] = 16;
    data["time"]["end"] = 22;

    render_to(cout, "{{ guests.1 }}", data);
    cout << endl;

    render_to(cout, "{{ time.start }} to {{ time.end }}pm ", data);
    cout << endl;

    string str;
    str = render(R"(Guest List:
    {% for guest in guests %}
        {{ loop.index1 }}: {{ guest }}
    {% endfor %} )", data);

    cout << str << endl;

    Template content_template = env.parse("Hello {{ neighbor }}");
    env.include_template("content", content_template);
    str = env.render("Content: {% include \"content\" %}", data);
    cout << str << endl;

    json j;

    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = { 1, 0, 2 };
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };
    j["morep"] = "{ \"happy\": true, \"pi\": 3.141, \"herderp\": \"A string literal\" }"_json;

    string s = j.dump();
    cout << s << endl;


    return 0;
}
