def get_num(msg, lo, hi, cast=int):
    while True:
        try:
            v = cast(input(msg))
            if lo <= v <= hi:
                return v
            print(f"Enter a value between {lo} and {hi}")
        except ValueError:
            print("Please enter a valid number.")

def exam_decision(days, syllabus, confidence, hours):
    score = (4 if days <= 1 else 3 if days <= 3 else 2 if days <= 7 else 1)
    score += (3 if syllabus < 40 else 2 if syllabus < 70 else 1)
    score += 2 if confidence <= 2 else 0
    print("\n--- AI DECISION REPORT ---")
    print("Exam urgency score:", score, "/ 9")

    if days <= 1 and syllabus < 50:
        print("Decision: Emergency revision plan\nAction: Focus on important topics and practise previous questions.")
    elif syllabus < 50 and hours >= 3:
        print("Decision: Intensive study plan\nAction: Learn basic concepts first and solve practical examples.")
    elif syllabus >= 80 and days <= 3:
        print("Decision: Revision plan\nAction: Revise completed topics and practise mock tests.")
    elif confidence <= 2:
        print("Decision: Improve confidence\nAction: Revise easy topics first, practise step by step.")
    elif hours < 1:
        print("Decision: Short study plan\nAction: Study one important topic.")
    else:
        print("Decision: Regular study plan\nAction: Complete pending topics, revise and practise daily.")

def daily_plan(hours):
    print("\n--- DAILY STUDY PLAN ---")
    if hours < 1:
        print("Study one important concept for 30 minutes.\nUse the remaining time for quick revision.")
    else:
        print("Concept learning:", round(hours * 0.6, 2), "hours")
        print("Problem practice:", round(hours * 0.3, 2), "hours")
        print("Quick revision:", round(hours * 0.1, 2), "hours")

print("=" * 45, "\n       AI STUDENT STUDY ASSISTANT\n" + "=" * 45)
while True:
    print("\n1. Start Student Assistant\n2. Exit")
    if get_num("Enter your choice: ", 1, 2) == 2:
        print("Thank you for using the AI assistant!")
        break
    name = input("\nEnter student name: ").strip() or "Student"
    days = get_num("Days left for exam (0-365): ", 0, 365)
    syllabus = get_num("Syllabus completed (0-100%): ", 0, 100)
    confidence = get_num("Confidence level (1-5): ", 1, 5)
    hours = get_num("Available study hours today: ", 0, 24, float)
    print("\nHello,", name, "\nAnalyzing your study situation...")
    exam_decision(days, syllabus, confidence, hours)
    daily_plan(hours)

print("\nAI analysis completed successfully.")