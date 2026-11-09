knowledge_base = [
    ("completed_all_subjects", "Ravi"),
    ("paid_exam_fee", "Ravi"),
    ("completed_all_subjects", "Priya"),
    ("paid_exam_fee", "Priya")
]
rules = [
    {
        "conditions": [
            ("completed_all_subjects", "?student"),
            ("paid_exam_fee", "?student")
        ],
        "conclusion": ("eligible_for_exam", "?student")
    },
    {
        "conditions": [
            ("eligible_for_exam", "?student")
        ],
        "conclusion": ("can_download_hall_ticket", "?student")
    }
]
def match_pattern(pattern, fact, bindings):
    new_bindings = bindings.copy()
    if len(pattern) != len(fact):
        return None
    for p, f in zip(pattern, fact):
        if isinstance(p, str) and p.startswith("?"):
            if p in new_bindings:
                if new_bindings[p] != f:
                    return None
            else:
                new_bindings[p] = f
        elif p != f:
            return None
    return new_bindings
def find_matches(conditions, facts, bindings=None):
    if bindings is None:
        bindings = {}
    if not conditions:
        return [bindings]
    results = []
    for fact in facts:
        new_bindings = match_pattern(
            conditions[0], fact, bindings
        )
        if new_bindings is not None:
            results.extend(
                find_matches(
                    conditions[1:],
                    facts,
                    new_bindings
                )
            )
    return results
def inference_engine(facts, rules):
    derived_facts = list(facts)
    while True:
        new_facts = []
        for rule in rules:
            matches = find_matches(
                rule["conditions"], derived_facts
            )
            for bindings in matches:
                conclusion = tuple(
                    bindings.get(item, item)
                    if isinstance(item, str)
                    and item.startswith("?")
                    else item
                    for item in rule["conclusion"]
                )
                if conclusion not in derived_facts:
                    new_facts.append(conclusion)
                    print("New fact derived:", conclusion)
        if not new_facts:
            break
        derived_facts.extend(new_facts)
    return derived_facts
print("INFERENCE SYSTEM")
print("------------------------")
print("Initial Knowledge Base:")
for fact in knowledge_base:
    print(fact)
all_facts = inference_engine(knowledge_base, rules)
print("\nFinal Knowledge Base:")
for fact in all_facts:
    print(fact)
student = input("Enter student name: ").strip().title()
if ("eligible_for_exam", student) in all_facts:
    print(student, "is ELIGIBLE for examination")
else:
    print(student, "is NOT ELIGIBLE for examination")
if ("can_download_hall_ticket", student) in all_facts:
    print("Student can download hall ticket")
else:
    print("Student cannot download hall ticket")