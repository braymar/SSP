# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build/Debug

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2.1" -D "JUCE_APP_VERSION_HEX=0x10201" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vst3-sdk -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0 -I../../../../mi -I ../../../common
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2.1" -D "JUCE_APP_VERSION_HEX=0x10201" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vst3-sdk -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  TARGET := clds.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build/Release

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2.1" -D "JUCE_APP_VERSION_HEX=0x10201" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vst3-sdk -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -O3 -I../../../../mi -I ../../../common
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.2.1" -D "JUCE_APP_VERSION_HEX=0x10201" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vst3-sdk -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  TARGET := clds.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/SSP_dd798310.o \
  $(OBJDIR)/SSPButton_f6a7ad22.o \
  $(OBJDIR)/SSPParam_83ec7d27.o \
  $(OBJDIR)/frame_transformation_a0b68cca.o \
  $(OBJDIR)/phase_vocoder_8b4e13ef.o \
  $(OBJDIR)/stft_f644a376.o \
  $(OBJDIR)/correlator_28b4fa59.o \
  $(OBJDIR)/granular_processor_9ce7a4cf.o \
  $(OBJDIR)/mu_law_8bcd3fb7.o \
  $(OBJDIR)/resources_649f74a7.o \
  $(OBJDIR)/random_3aa6eea.o \
  $(OBJDIR)/atan_dc30eefd.o \
  $(OBJDIR)/units_9838f790.o \
  $(OBJDIR)/PluginProcessor_a059e380.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/juce_audio_basics_2442e4ea.o \
  $(OBJDIR)/juce_audio_devices_a4c8a728.o \
  $(OBJDIR)/juce_audio_formats_d349f0c8.o \
  $(OBJDIR)/juce_audio_processors_44a134a2.o \
  $(OBJDIR)/juce_core_aff681cc.o \
  $(OBJDIR)/juce_data_structures_bdd6d488.o \
  $(OBJDIR)/juce_events_79b2840.o \
  $(OBJDIR)/juce_graphics_c8f1e7a4.o \
  $(OBJDIR)/juce_gui_basics_a630dd20.o \
  $(OBJDIR)/juce_gui_extra_7767d6a8.o \
  $(OBJDIR)/juce_PluginUtilities_e2e19a34.o \
  $(OBJDIR)/juce_VST_Wrapper_bb62e93d.o \
  $(OBJDIR)/juce_VST3_Wrapper_77e7c73b.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking clds
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning clds
	@$(CLEANCMD)

strip:
	@echo Stripping clds
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/SSP_dd798310.o: ../../../common/SSP.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SSP.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SSPButton_f6a7ad22.o: ../../../common/SSPButton.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SSPButton.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SSPParam_83ec7d27.o: ../../../common/SSPParam.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SSPParam.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/frame_transformation_a0b68cca.o: ../../../../mi/clouds/dsp/pvoc/frame_transformation.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling frame_transformation.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/phase_vocoder_8b4e13ef.o: ../../../../mi/clouds/dsp/pvoc/phase_vocoder.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling phase_vocoder.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/stft_f644a376.o: ../../../../mi/clouds/dsp/pvoc/stft.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling stft.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/correlator_28b4fa59.o: ../../../../mi/clouds/dsp/correlator.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling correlator.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/granular_processor_9ce7a4cf.o: ../../../../mi/clouds/dsp/granular_processor.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling granular_processor.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/mu_law_8bcd3fb7.o: ../../../../mi/clouds/dsp/mu_law.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling mu_law.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/resources_649f74a7.o: ../../../../mi/clouds/resources.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling resources.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/random_3aa6eea.o: ../../../../mi/stmlib/utils/random.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling random.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/atan_dc30eefd.o: ../../../../mi/stmlib/dsp/atan.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling atan.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/units_9838f790.o: ../../../../mi/stmlib/dsp/units.cc
	-@mkdir -p $(OBJDIR)
	@echo "Compiling units.cc"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_2442e4ea.o: ../../JuceLibraryCode/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_a4c8a728.o: ../../JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_d349f0c8.o: ../../JuceLibraryCode/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_44a134a2.o: ../../JuceLibraryCode/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_aff681cc.o: ../../JuceLibraryCode/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_bdd6d488.o: ../../JuceLibraryCode/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_79b2840.o: ../../JuceLibraryCode/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_c8f1e7a4.o: ../../JuceLibraryCode/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_a630dd20.o: ../../JuceLibraryCode/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_7767d6a8.o: ../../JuceLibraryCode/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_e2e19a34.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginUtilities.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_bb62e93d.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST3_Wrapper_77e7c73b.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST3_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
