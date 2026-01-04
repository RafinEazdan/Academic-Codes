import re

def normalize_text(text):
    text = text.replace("—", "-")  # em dash
    text = re.sub(r"[“”]", '"', text)  # fancy quotes to normal
    text = re.sub(r"[‘’]", "'", text)  # fancy single quotes to normal
    return text

# Normalize all flashcard text
normalized_flashcards = [(normalize_text(front), normalize_text(back)) for front, back in flashcards]

# Create PDF document again with normalized text
pdf = PDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()

# Add flashcards to the PDF
for i, (front, back) in enumerate(normalized_flashcards, 1):
    pdf.chapter_title(i, front)
    pdf.chapter_body(back)

# Save the fixed PDF
pdf_path = "/mnt/data/design_patterns_flashcards.pdf"
pdf.output(pdf_path)

pdf_path