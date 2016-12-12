#ifndef {{include_guard_name}}
#define {{include_guard_name}}

#include <stdlib.h>

struct {{struct_name}} {
    ## for property in properties:
    {{property.type}} {{property.name}};
    ## endfor
};

## if no_constructor
## elif define_stack_constructor:
struct {{struct_name}} {{struct_name}}_new() {
    struct {{struct_name}} result;

    ## for property in properties:
    result.{{property.name}} = {{property.default_value}};
    ## endfor
    return result;
}

void {{struct_name}}_delete(struct {{struct_name}} to_delete) {
    ## for property in properties:
    ## if property.destructor:
    {{property.destructor}}(to_delete.{{property.name}});
    ## endif
    ## endfor
}

## else
struct {{struct_name}} * {{struct_name}}_new() {
    struct {{struct_name}} * result = (struct {{struct_name}} *) malloc(sizeof(struct {{struct_name}}));

    ## for property in properties:
    result->{{property.name}} = {{property.default_value}};
    ## endfor
    return result;
}

void {{struct_name}}_delete(struct {{struct_name}} * to_delete) {
    ## for property in properties:
    ## if property.destructor:
    {{property.destructor}}(to_delete->{{property.name}});
    ## endif
    ## endfor
    free(to_delete);
}

## endif
#endif
