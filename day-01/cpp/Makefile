SRCDIR := src
TARGET := submarine

all: $(TARGET)

$(TARGET): % : $(SRCDIR)/%
	@cp $^ .

clean:
	$(RM) $(TARGET) $(addprefix $(SRCDIR)/,$(TARGET))

.PHONY: all clean