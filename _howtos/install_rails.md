---
layout: page
title: Install Rails in Debian 
---

# Step 1: Clean
- If this is not a fresh installation, clean up first:
```bash
# remove your existing rbenv installation
rm -rf ~/.rbenv
rm -rf ~/gems
rm -rf ~/.local/share/gem
rm -rf ~/.gem
# Remove old rbenv/gem configuration from your shell:
grep -nE 'rbenv|GEM_HOME|GEM_PATH|/gems/bin' ~/.bashrc ~/.profile 2>/dev/null
# Edit the bashrc file
vim ~/.bashrc
# Remove lines such as:
export GEM_HOME="$HOME/gems"
export GEM_PATH="$HOME/gems"
export PATH="$HOME/gems/bin:$PATH"
export PATH="$HOME/.rbenv/bin:$PATH"
eval "$(rbenv init - bash)"
# Don't forget to check:  ~/.profile
```
- In a clean shell (`exec bash -l`), verify that ruby, gem, and rails are gone:
```bash
command -v ruby
command -v gem
command -v rails
```
- Remove Debian's ruby packages
  - This will show you the packages currently installed: `dpkg -l | grep -E '^ii.*ruby'`
  - This will remove the packages: `sudo apt purge 'ruby*' && sudo apt autoremove`
  - Update: `sudo apt update && sudo apt upgrade`

# Step 2: Continue or start here
If this is a new/clean debian installation, start here. 
- Install Ruby build dependencies. `rbenv` builds Ruby from source, so Debian needs the compiler and development libraries.
```bash
sudo apt install -y \
    build-essential \
    autoconf \
    bison \
    rustc \
    libssl-dev \
    libyaml-dev \
    libreadline-dev \
    zlib1g-dev \
    libncurses5-dev \
    libffi-dev \
    libgdbm-dev \
    libdb-dev \
    uuid-dev
```

## Step 3: Install rbenv
```bash
git clone https://github.com/rbenv/rbenv.git ~/.rbenv

## Add to bashrc
echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(rbenv init - bash)"' >> ~/.bashrc

## Reload bash
exec bash -l

## Verify
rbenv --version

## Expected output
## rbenv 1.x.x
```

## Step 4: Install Ruby Build and ruby
`rbenv` itself does not contain the Ruby versions. `ruby-build` provides the definitions needed to compile them.

```bash
git clone https://github.com/rbenv/ruby-build.git "$(rbenv root)/plugins/ruby-build"

## Verify that the version you want is available. Ex: 4.0.6
rbenv install -l | grep '^4\.0\.6$'

## Expected output
4.0.6

## Install ruby
rbenv install 4.0.6
rbenv global 4.0.6
rbenv rehash
ruby --version  # ruby 4.0.6 ...
which ruby      # /home/user/.rbenv/shims/ruby
gem env home    # /home/USER/.rbenv/versions/4.0.6/lib/ruby/gems/4.0.0
gem env path    # /home/USER/.local/share/gem/ruby/4.0.0:/home/rap/.rbenv/versions/4.0.6/lib/ruby/gems/4.0.0
## Warning: These two commands should return nothing:
echo "$GEM_HOME"
echo "$GEM_PATH"
# DO NOT manually set those vars. 
which gem       # /home/USER/.rbenv/shims/gem
```

## Step 6: Installing Rails and Jekyll

```bash
gem update --system
gem install bundler
# verify
gem --version
bundler --version
# Install rails and jekyll
gem install rails
gem install jekyll
rbenv rehash
# Verify
rails --version
jekyll --version
```
Step 7: Verify there is only one Ruby/RDoc environment
```bash
ruby -v
gem -v
rails -v

which ruby
which gem
which rails

gem env home
gem env path

gem list rdoc
gem list rbs
```
The output should be:
```bash
ruby 4.0.6 (2026-07-14 revision 03b6d3f889) +PRISM [x86_64-linux]
4.0.19
Rails 8.1.3.1
/home/user/.rbenv/shims/ruby
/home/user/.rbenv/shims/gem
/home/user/.rbenv/shims/rails
/home/user/.rbenv/versions/4.0.6/lib/ruby/gems/4.0.0
/home/user/.local/share/gem/ruby/4.0.0:/home/user/.rbenv/versions/4.0.6/lib/ruby/gems/4.0.0

*** LOCAL GEMS ***

rdoc (8.0.0, 7.0.4)

*** LOCAL GEMS ***

rbs (4.2.0, 3.10.0)
```

The important architecture should now be:
```bash
/home/user/.rbenv/
├── bin/
├── shims/
│   ├── ruby
│   ├── gem
│   ├── bundle
│   └── rails
├── versions/
│   └── 4.0.6/
│       ├── bin/
│       └── lib/ruby/
│           └── gems/4.0.0/
└── plugins/
    └── ruby-build/
```