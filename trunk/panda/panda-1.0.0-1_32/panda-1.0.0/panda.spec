Summary:  panda windows manager
Name:  panda
Version: 1.0.0 
Release: 1
License: GPL
Group: Applications/Editors
Source: %{name}-%{version}-%{release}.tar.gz
Buildroot: %{_tmppath}/%{name}-%{version}-root

%description

 A simple windows manager 

%prep
%setup -q

%build

qmake
export LD_LIBRARY_PATH=/usr/local/fontconfig/lib
make

%install
rm -fr $RPM_BUILD_ROOT

mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/lib
mkdir -p $RPM_BUILD_ROOT/usr/local/panda
mkdir -p $RPM_BUILD_ROOT/usr/share/xsessions

cp    panda $RPM_BUILD_ROOT/usr/local/panda
cp    panda.sh $RPM_BUILD_ROOT/usr/local/panda/panda.sh
cp    panda.sh $RPM_BUILD_ROOT/usr/bin
cp    panda.cfg $RPM_BUILD_ROOT/usr/local/panda
cp    panda-gdm.desktop $RPM_BUILD_ROOT/usr/share/xsessions
cp -r language $RPM_BUILD_ROOT/usr/local/panda
cp -r  theme $RPM_BUILD_ROOT/usr/local/panda
cp -r libs $RPM_BUILD_ROOT/usr/local/panda


%files
#%defattr(-,root,root)
/usr/bin/panda.sh
/usr/local/panda/*
/usr/share/xsessions/*
%clean
rm -rf $RPM_BUILD_ROOT

