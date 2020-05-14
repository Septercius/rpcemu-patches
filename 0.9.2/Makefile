.SILENT: patch package

all: patch

RPCEMUVERSION=0.9.2
PATCHNAME=mac-patch
PATCHVERSION=4

# Do not change the below.

EXTRASDIR=extras
LEAFNAME=rpcemu-$(RPCEMUVERSION)-$(PATCHNAME)-v$(PATCHVERSION)
PACKAGENAME=$(LEAFNAME).zip
RELEASEDIR=../Releases
TARGET=$(LEAFNAME).patch
WORKDIR=tmp
ZIPOPTS=-r -q

patch:
	@rm -rf $(TARGET)
	@touch $(TARGET)
	@for i in diffs/* ; do cat $$i >> $(TARGET); done

package: patch
	rm -rf $(WORKDIR)
	mkdir $(WORKDIR)
	cp $(TARGET) $(WORKDIR)/
	if [ -d $(EXTRASDIR) ]; then cp -R $(EXTRASDIR)/* $(WORKDIR)/ ; fi
	dot_clean $(WORKDIR)/

	pushd $(WORKDIR) > /dev/null && zip $(ZIPOPTS) ../$(PACKAGENAME) * && popd >/dev/null

	cp $(PACKAGENAME) $(RELEASEDIR)

clean:
	rm -rf $(WORKDIR)
	rm -rf $(TARGET)
	rm -rf $(PACKAGENAME)
